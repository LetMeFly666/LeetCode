#!/usr/bin/bash

PREFIX="${1:-}"
THREADS="${2:-$(nproc)}"
ORIG_REPO="$(pwd)"
MEM_FILE_PATH="$(realpath "../memFiles")"
FLAG="$MEM_FILE_PATH/flag"
ORIGINAL_COMMIT_MSG="$(git log -1 --pretty=%B)"

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

if [ -d "$MEM_FILE_PATH" ]; then
    sudo umount "$MEM_FILE_PATH"
    rm -rf "$MEM_FILE_PATH"
fi
mkdir -p "$MEM_FILE_PATH"
sudo mount -t ramfs ramfs "$MEM_FILE_PATH"
sudo chown -R $USER:$USER "$MEM_FILE_PATH"

firstDir="$MEM_FILE_PATH/1"
echo "cp first dir"
rsync -a "$ORIG_REPO/" "$firstDir/"
echo "cp first dir done"
for i in $(seq 2 "$THREADS"); do
    echo "cp dir $i"
    rsync -a "$firstDir/" "$MEM_FILE_PATH/$i/"
done
echo "all dirs copied"

pids=()
worker() {
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
        ((round++))
        if (( round % 100 == 0 )); then
            echo "🧵 [$id] tried=$round sha=${sha:0:12}"
        fi

        if [[ "$sha" == "$PREFIX"* ]]; then
            echo "worker $id: FOUND!"
            echo "$1" > "$FLAG"
            rm -rf "$ORIG_REPO/.git"
            rsync -a --delete "$dir/.git" "$ORIG_REPO/"
            echo "worker $id: result synced to $ORIG_REPO/.git; exiting"
            break
        fi
    done

}
for i in $(seq 1 "$THREADS"); do
    worker "$i" & pids+=($!)
done
# wait -n
# echo "parent: detected a worker finished; setting finished"
# for pid in "${pids[@]}"; do
#     if kill -0 "$pid" 2>/dev/null; then
#         kill "$pid" 2>/dev/null || true
#     fi
# done
wait
sudo umount "$MEM_FILE_PATH"
rm -rf "$MEM_FILE_PATH"
echo "parent: all workers exited"
