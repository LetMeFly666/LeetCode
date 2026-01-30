#!/usr/bin/env bash
set -euo pipefail

PREFIX="${1:-}"
THREADS="${2:-$(nproc)}"

if [[ -z "$PREFIX" ]]; then
  echo "❌ 用法: $0 <hex-prefix> [threads]"
  exit 1
fi

if ! [[ "$PREFIX" =~ ^[0-9a-fA-F]+$ ]]; then
  echo "❌ 前缀必须是十六进制"
  exit 1
fi

if (( ${#PREFIX} > 40 )); then
  echo "❌ SHA1 最多 40 位"
  exit 1
fi

echo "🚀 prefix=$PREFIX  threads=$THREADS"

ORIG_REPO="$(pwd)"
WORKDIR="$(mktemp -d /dev/shm/git-hash.XXXXXX 2>/dev/null || mktemp -d)"

FOUND_FILE="$WORKDIR/found"
export FOUND_FILE PREFIX

cleanup() {
  rm -rf "$WORKDIR"
}
trap cleanup EXIT

echo "📁 workdir=$WORKDIR"
echo "----------------------------------------"

worker() {
  local id="$1"
  local repo="$WORKDIR/repo_$id"

  cp -a "$ORIG_REPO" "$repo"
  cd "$repo"

  local i=0
  while [[ ! -f "$FOUND_FILE" ]]; do
    export GIT_COMMITTER_DATE="$(date +%s.%N)"
    export GIT_AUTHOR_DATE="$GIT_COMMITTER_DATE"

    git commit --amend -S --no-edit --allow-empty >/dev/null 2>&1

    sha="$(git rev-parse HEAD)"
    ((i++))

    if (( i % 100 == 0 )); then
      echo "🧵 [$id] tried=$i sha=${sha:0:12}"
    fi

    if [[ "$sha" == "$PREFIX"* ]]; then
      echo "🎯 [$id] FOUND: $sha"
      echo "$repo" > "$FOUND_FILE"
      break
    fi
  done
}

# 启动线程
for i in $(seq 1 "$THREADS"); do
  worker "$i" &
done

# 等待结果
while [[ ! -f "$FOUND_FILE" ]]; do
  sleep 0.05
done

WINNER_REPO="$(cat "$FOUND_FILE")"

echo "----------------------------------------"
echo "✅ Winner: $WINNER_REPO"
echo "📦 Applying result..."

# 停掉其它线程
pkill -P $$ || true

# 把成功结果落盘
rm -rf "$ORIG_REPO/.git"
cp -a "$WINNER_REPO/.git" "$ORIG_REPO/"

echo "🎉 Done!"
git rev-parse HEAD
