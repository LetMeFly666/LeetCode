#!/usr/bin/env bash

set -euo pipefail

PREFIX="${1:-}"

# ========= 参数校验 =========
if [[ -z "$PREFIX" ]]; then
  echo "❌ 用法: $0 <sha-prefix>"
  exit 1
fi

# 转小写（git sha 是小写）
PREFIX="$(echo "$PREFIX" | tr 'A-F' 'a-f')"

# 必须是 hex
if ! [[ "$PREFIX" =~ ^[0-9a-f]+$ ]]; then
  echo "❌ 前缀不合法：只能包含 [0-9a-f]"
  exit 1
fi

LEN=${#PREFIX}

# 给一个“理性提醒”
if (( LEN > 8 )); then
  echo "⚠️  警告：前缀长度 = $LEN"
  echo "⚠️  理论期望尝试次数 ≈ 16^$LEN"
  echo "⚠️  这可能需要非常久（甚至几天/几周）"
fi

echo "🚀 目标前缀: $PREFIX"
echo "🔁 使用命令: git commit --amend -nS --no-edit --allow-empty"
echo "----------------------------------------"

# ========= 主循环 =========
COUNT=0
START_TS=$(date +%s)

while true; do
  git commit --amend -nS --no-edit --allow-empty >/dev/null 2>&1

  SHA=$(git rev-parse HEAD)
  COUNT=$((COUNT + 1))

  if [[ "$SHA" == "$PREFIX"* ]]; then
    END_TS=$(date +%s)
    COST=$((END_TS - START_TS))
    echo "🎉 命中！"
    echo "✅ SHA: $SHA"
    echo "🔢 尝试次数: $COUNT"
    echo "⏱️  用时: ${COST}s"
    break
  fi

  # 每 100 次输出一次状态
  if (( COUNT % 100 == 0 )); then
    NOW=$(date +%s)
    ELAPSED=$((NOW - START_TS))
    printf "⏳ tried=%d  elapsed=%ds  current=%s\n" \
      "$COUNT" "$ELAPSED" "$SHA"
  fi
done
