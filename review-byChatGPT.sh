#!/usr/bin/env bash

set -e

PR="${1:-}"

if [ -z "$PR" ]; then
    echo "Usage: $0 <PR_NUMBER>"
    exit 1
fi

cat > /tmp/pr_review.md <<'EOF'
## Review

### 🔴 Must fix

#### 1. Remove `testForSnpppet*` temporary files

The following files look like debugging/testing artifacts rather than repository content:

- `testForSnpppet.md`
- `testForSnpppet.md.cpp`
- `testForSnpppet.md.tex`

They contain VSCode snippet experiments and temporary notes. Please remove them or move them into a dedicated test/docs directory.

---

#### 2. Check README blog link

The newly added README entry appears to contain a suspicious URL:

```
Other-Git-CustomMergingScriptOther-VSCode-Snippets-Markdown_LaTeX
```

It looks like two article slugs may have been concatenated accidentally.

Please verify and fix the link.

---

#### 3. Confirm `.commitmsg` deletion

`.commitmsg` was deleted.

Please confirm this file is no longer used by any git hooks or tooling before removing it.

---

### 🟡 Suggestions

#### 4. LeetCode 628 solution can be optimized

Current implementation:

```cpp
ranges::sort(nums);
```

has:

```
Time: O(n log n)
Space: O(log n)
```

This is correct, but the problem can also be solved in:

```
Time: O(n)
Space: O(1)
```

by maintaining:

- three maximum values
- two minimum values

The current approach is acceptable, but consider whether the intended solution should demonstrate the linear scan method.

---

#### 5. Improve explanation of negative number cases

The proof section is correct, but some wording may confuse readers:

> 必须选三个负数的时候？说明只有三个负数，没得挑。

and

> 必须选且只选一个负数的时候？

These cases are true, but the explanation could be clearer by first stating:

- If non-negative choices exist, an odd number of negative numbers is never optimal.
- The only remaining cases naturally fall into the two candidate formulas.

---

#### 6. Add `__main__` guard in `OSC8terminalLink.py`

Currently:

```python
print(osc8(...))
```

executes during import.

Consider:

```python
if __name__ == "__main__":
    ...
```

to avoid side effects.

---

#### 7. Typo

Filename:

```
testForSnpppet
```

should probably be:

```
testForSnippet
```

---

#### 8. VSCode snippet documentation wording

This sentence:

> 如果你选中markdown代码段的话，是不支持scope字段的

could be more precise.

Language-specific snippets already have their language scope, while global snippets support the `scope` field.

---

## Summary

Overall this PR is functional and mostly good.

However, before merging I recommend fixing:

- remove temporary snippet test files
- verify README URL
- confirm `.commitmsg` removal

The remaining points are improvement suggestions.

by ChatGPT
EOF

gh pr review "$PR" \
    --request-changes \
    --body-file /tmp/pr_review.md
