#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <pr_num>"
    exit 1
fi

PR_NUM="$1"

REVIEW_BODY=$(cat <<'EOF'
by ChatGPT

## Review Summary

Request changes

## Review Comments

### 1. Critical: C++ solution modifies input string in-place without documenting the side effect

`smallestPalindrome(string& s)` receives a non-const reference and directly overwrites `s`.

For a LeetCode solution this may work, but the implementation contract is different from the Python version and from the common expectation that the input parameter is not modified.

建议：
- 改为返回新字符串；
- 或在题解中明确说明“原字符串会被原地修改”。

---

### 2. Documentation complexity analysis is inconsistent

The Python sorting solution claims:

```
时间复杂度 O(len(s)+C)
```

but the implementation uses:

```python
t = sorted(s[: len(s) // 2])
```

The sorting operation costs `O(n log n)`, not `O(n+C)`.

建议修正复杂度说明，例如：

- 排序版本：时间复杂度 `O(n log n)`，空间复杂度 `O(n)`；
- 计数版本：时间复杂度 `O(n+C)`，空间复杂度 `O(C)`。

---

### 3. Python solution space complexity is inaccurate

The article states the sorting method uses `O(C)` space, but:

```python
t = sorted(s[: len(s) // 2])
```

creates a new list containing half of the string.

Therefore the auxiliary space is `O(n)`.

---

### 4. README table formatting regression

The diff changes:

```
|part|含义|举例|
```

to:

```
||含义|举例|
```

This removes the first column header and makes the Markdown table less readable.

建议恢复原来的表头。

---

### 5. Minor: typo in documentation

The diff changes:

```
heci
```

to:

```
jpeg
```

while fixing one typo, but the surrounding text previously also contained inconsistent format naming. Please verify all file type names (`jpeg`, `heic`) are consistent.

---

## Positive feedback

- The algorithm implementations are concise and match the problem requirement.
- The counting solution correctly uses character frequency and constructs the lexicographically smallest palindrome.
- The README update is consistent with adding the new LeetCode solution.

## Final verdict

当前提交存在复杂度说明错误和文档回归问题，建议修复后合并。

Request changes.
EOF
)

gh pr review "$PR_NUM" --request-changes --body "$REVIEW_BODY"
