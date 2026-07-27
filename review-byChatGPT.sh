#!/usr/bin/env bash

set -euo pipefail

PR="${1:-}"

if [[ -z "$PR" ]]; then
    echo "Usage: $0 <PR_NUMBER>"
    exit 1
fi

gh pr review "$PR" --request-changes --body "$(cat <<'EOF'
## Review

### 🔴 必须修复

暂无阻塞性问题。

---

### 🟡 建议改进

#### 1. `maxProduct` 初始化逻辑依赖题目约束，建议增加说明

当前实现：

```cpp
int mx1 = 1, mx2 = 1;
```

依赖 LeetCode 1464 中 `nums[i] >= 1` 的约束。

如果未来代码被复用到允许负数或 0 的场景，初始化为 1 会导致错误结果。建议：

- 在题解中明确说明该初始化依赖题目约束；
- 或使用 `INT_MIN` 初始化，使算法更加通用。

#### 2. 变量命名可以更语义化

`mx1`、`mx2` 能表达含义，但可读性一般。

例如：

```cpp
int secondMax = 1;
int maxValue = 1;
```

会更容易理解。

#### 3. README 中的待办事项改动需要确认是否属于本 PR 范围

新增：

```
- [ ] Link tester（发布完成渲染完毕后，检测本次改动涉及到的链接是否正常）
```

如果该 PR 主要目的是提交 LeetCode 1464 题解，这属于无关改动，建议拆分到单独 PR，保持提交粒度。

---

### 🟢 正向反馈

- LeetCode 1464 的一次遍历解法正确，时间复杂度 `O(n)`，空间复杂度 `O(1)`。
- 删除临时 snippet 测试文件和 OSC8 测试脚本符合清理仓库的目的。
- 新增题解内容与代码保持一致。

---

### Summary

整体代码和题解没有明显错误，可以合并。

建议合并前确认 README 的无关改动是否需要拆分，并补充初始化条件的说明。

by ChatGPT
EOF
)"
