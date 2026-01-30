#!/usr/bin/env bash
set -euo pipefail

FLAG=/tmp/finished.flag
rm -f "$FLAG"

pids=()

# 子任务示例：运行若干秒后退出
worker_long() {
  local id=$1
  local dur=$2
  echo "worker $id: will run ${dur}s"
  sleep "$dur"
  echo "worker $id: done"
}

# 启动几个子进程（示例不同运行时间）
worker_long 1 8 & pids+=($!)
worker_long 2 5 & pids+=($!)
worker_long 3 12 & pids+=($!)
worker_long 4 3 & pids+=($!)
worker_long 5 10 & pids+=($!)

# 等待任意一个子进程结束
wait -n

# 第一个结束的子进程触发 finished
echo "parent: detected a worker finished; setting finished"
touch "$FLAG"

# 终止尚在运行的子进程
for pid in "${pids[@]}"; do
  if kill -0 "$pid" 2>/dev/null; then
    kill "$pid" 2>/dev/null || true
  fi
done

# 等待剩余子进程退出（可省）
wait
echo "parent: all workers exited"