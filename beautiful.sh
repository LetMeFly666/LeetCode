#!/usr/bin/bash
set -euo pipefail
START_TS=$(date +%s)

PREFIX="${1:-}"
THREADS="${2:-$(nproc)}"
ORIG_REPO="$(pwd)"
MEM_FILE_PATH="$(realpath "../memFiles")"
FLAG="$MEM_FILE_PATH/flag"
ORIGINAL_COMMIT_MSG="$(git log -1 --pretty=%B)"

# -------- cleanup logic --------
CLEANED=0
cleanup() {
    [[ $CLEANED -eq 1 ]] && return
    CLEANED=1

    echo
    echo "🧹 cleanup: stopping workers & unmounting..."
    echo "🧹 cleanup at +$(elapsed)"

    # stop workers
    if [[ -n "${pids[*]:-}" ]]; then
        for pid in "${pids[@]}"; do
            echo "🧹 killing pid $pid"
            kill "$pid" 2>/dev/null || true
        done
        wait 2>/dev/null || true
    fi

    echo "sleep 2 seconds"
    sleep 2

    # unmount ramfs if mounted
    if mountpoint -q "$MEM_FILE_PATH"; then
        sudo umount "$MEM_FILE_PATH" || {
            echo "⚠️ umount failed, forcing lazy umount"
            sudo umount -l "$MEM_FILE_PATH" || true
        }
    fi

    echo "rm -rf $MEM_FILE_PATH"
    rm -rf "$MEM_FILE_PATH"
    echo "🧹 cleanup done"
}
trap cleanup INT TERM EXIT
# --------------------------------

elapsed() {
    local now=$(( $(date +%s) ))
    local elapsed=$(( now - START_TS ))

    local hours=$(( elapsed / 3600 ))
    local minutes=$(( (elapsed % 3600) / 60 ))
    local seconds=$(( elapsed % 60 ))

    local output=""

    (( hours > 0 )) && output+="${hours}h"
    (( minutes > 0 )) && output+="${minutes}m"
    output+="${seconds}s"

    echo "$output"
}

if [[ -z "$PREFIX" ]]; then
    echo "Usage: $0 <hex-prefix> [threads]"
    exit 1
fi
if ! [[ "$PREFIX" =~ ^[0-9a-fA-F]+$ ]]; then
    echo "prefix must be in range [0-9a-fA-F]"
    exit 1
fi
if (( ${#PREFIX} > 40 )); then
    echo "SHA1's max length is 40"
    exit 1
fi
echo "prefix=$PREFIX  threads=$THREADS"

if mountpoint -q "$MEM_FILE_PATH"; then
    sudo umount "$MEM_FILE_PATH"
fi
rm -rf "$MEM_FILE_PATH"
mkdir -p "$MEM_FILE_PATH"
sudo mount -t ramfs ramfs "$MEM_FILE_PATH"
sudo chown -R "$USER:$USER" "$MEM_FILE_PATH"

firstDir="$MEM_FILE_PATH/originalDir"
echo "cp original dir"
rsync -a "$ORIG_REPO/" "$firstDir/"
echo "cp original dir done"

pids=()
worker() {
    set +e
    local id=$1
    local dir="$MEM_FILE_PATH/$id"
    cd "$dir"
    echo "worker $id: started at $dir"

    local round=0
    while true; do
        if [ -e "$FLAG" ]; then
            echo "worker $id: detected finished flag; exiting"
            return
        fi

        git commit --amend -S --no-edit --allow-empty -m "$(printf "%s\n\nworker=%s round=%s" "$ORIGINAL_COMMIT_MSG" "$id" "$round")" >/dev/null 2>&1
        sha="$(git rev-parse HEAD)"
        # echo "worker $id: try=$round elapsed=$(elapsed) sha=$sha"
        ((round++))
        if (( round % 100 == 0 )); then
            echo "🧵 [$id] tried=$round elapsed=$(elapsed) sha=$sha"
        fi

        if [[ "$sha" == "$PREFIX"* ]]; then
            echo "🎯 worker $id: FOUND $sha after $(elapsed)"
            echo "$id" > "$FLAG"
            rm -rf "$ORIG_REPO/.git"
            rsync -a --delete "$dir/.git" "$ORIG_REPO/"
            echo "worker $id: result synced to $ORIG_REPO/.git; exiting"
            break
        fi
    done
}
for i in $(seq 1 "$THREADS"); do
    if [[ "$i" -eq "$THREADS" ]]; then
        echo "mv dir $i"
        mv "$firstDir" "$MEM_FILE_PATH/$i"
    else
        echo "cp dir $i"
        rsync -a "$firstDir/" "$MEM_FILE_PATH/$i/"
    fi
    worker "$i" & pids+=($!)
done

wait
echo "parent: all workers exited"
