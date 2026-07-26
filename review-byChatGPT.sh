#!/usr/bin/env bash

set -euo pipefail

PR="${1:-}"

if [[ -z "$PR" ]]; then
    echo "Usage: $0 <PR_NUMBER>"
    exit 1
fi

read -r -d '' REVIEW <<'EOF' || true
## Review

### 🔴 Must fix

#### 1. Remove temporary VSCode snippet test files

The following files look like local debugging artifacts rather than repository content:

- `testForSnipppet.md`
- `testForSnipppet.md.cpp`
- `testForSnipppet.md.tex`

Please remove them or move them into a dedicated documentation/test area.

#### 2. Fix typo in filenames

`testForSnipppet` appears to contain an extra `p`.

Consider renaming it to:

```
testForSnippet
```

#### 3. Confirm `.commitmsg` deletion

`.commitmsg` was deleted in this PR.

Please verify that no git hooks, scripts, or automation still depend on it before merging.

---

### 🟡 Suggestions

#### 4. Consider O(n) solution for LeetCode 628

The current implementation sorts the array:

```cpp
ranges::sort(nums);
```

This is correct, but the problem can also be solved with O(n) time and O(1) extra space by maintaining:

- three maximum values
- two minimum values

The current solution is acceptable if simplicity is preferred.

#### 5. Add `__main__` guard in `OSC8terminalLink.py`

The script currently executes `print(...)` at import time.

Consider wrapping demo code:

```python
if __name__ == "__main__":
    ...
```

to avoid import side effects.

#### 6. Improve explanation wording in LeetCode 628 article

The proof is correct, but the negative-number classification could be made clearer by first explaining:

- If non-negative choices exist, selecting an odd number of negative numbers is generally not optimal.
- The optimal candidates reduce to:
  - three largest numbers
  - two smallest numbers plus the largest number

---

### Summary

Overall this PR is functional and the main changes look reasonable.

Before merging, I recommend:
- remove temporary snippet test files
- verify `.commitmsg` removal
- fix typo naming

The remaining items are improvement suggestions.

by ChatGPT
EOF

gh pr review "$PR" --request-changes --body "$REVIEW"
