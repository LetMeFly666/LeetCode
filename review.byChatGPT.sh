#!/usr/bin/env bash
###
 # @Author: LetMeFly
 # @Date: 2026-07-14 11:41:38
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-07-14 11:41:58
### 

set -euo pipefail

REVIEW_BODY=$(cat <<'EOF'
## Review

整体实现正确，算法使用的是 **0-1 BFS**，代码质量较高，可以通过。

几个 minor comments：

### 1. 标题和 tag 建议调整

当前标题：

> 3286.穿越网格图的安全路径：“优先”队列

实际代码使用 `deque` 实现 0-1 BFS，并非 priority_queue。

建议：

```suggestion
3286.穿越网格图的安全路径：0-1 BFS
```

---

### 2. 复杂度描述

当前：

> 时间复杂度 O(size(grid))

建议：

```suggestion
时间复杂度 O(mn)
```

---

### 3. typo 修正

当前：

> 制止拼接完$9$为止。

建议：

```suggestion
直到拼接完$9$为止。
```

---

### 4. 优先队列描述

当前：

> 可以使用一个优先队列，每次队列中代价最小的位置出队。

建议：

```suggestion
可以使用 Dijkstra 求最小代价路径。由于边权只有 0 和 1，可以进一步优化为 0-1 BFS。
```

---

Approve.
EOF
)

gh pr review \
  --approve \
  --body "$REVIEW_BODY"