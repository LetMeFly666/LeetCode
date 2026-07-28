#!/usr/bin/env bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <pr_num>"
    exit 1
fi

PR_NUM="$1"

REVIEW_FILE="$(mktemp)"

cat > "$REVIEW_FILE" <<'EOF'
by ChatGPT

## Review Summary

Request changes

## Review Comments

### 1. Critical: livp_export.py may recursively process its own output directory

`os.walk(src)` only skips the output directory when:

```python
if os.path.abspath(root) == os.path.abspath(output):
    continue
```

However, `os.walk` has already populated `dirs`, so traversal can still descend into generated directories in some cases.

It is safer to prune `dirs` in-place:

```python
dirs[:] = [
    d for d in dirs
    if os.path.abspath(os.path.join(root, d)) != os.path.abspath(output)
]
```

Otherwise rerunning the exporter may process previously generated files.

---

### 2. Critical: live pair matching does not enforce the documented naming rule

The document states that matching requires:

```
xxx.jpeg.jpeg + xxx.jpeg.mov
xxx.HEIC.heic + xxx.HEIC.mov
```

with the same filename stem.

But the implementation:

```python
base, ext = os.path.splitext(os.path.basename(f))
```

only compares the stem after removing one extension.

This may accept combinations that are not intended to be live photos. Please add explicit validation for the supported naming format.

---

### 3. Critical: script dependency name is inconsistent

`pack_live()` invokes:

```python
livp_pack.py
```

but the document refers to several names:

- `livp_pack1.py`
- `live_pack1.py`
- `livp_pack.py`

This can directly cause runtime failure.

Please choose one filename and keep the article and implementation consistent.

---

### 4. Documentation and implementation behavior are inconsistent

The article describes strict matching:

> xxx.jpeg.jpeg + xxx.jpeg.mov  
> xxx.HEIC.heic + xxx.HEIC.mov

but the implementation accepts broader combinations such as:

```
xxx.jpg + xxx.mov
```

Either the code should enforce the documented rule, or the documentation should be updated.

---

### 5. Minor: unused imports should be removed

There are unused imports in the sample scripts, for example:

```python
import subprocess
```

where it is not used.

Removing unused imports improves readability for readers copying the scripts.

---

## Final verdict

The reverse engineering result is valuable, but the submitted implementation still has correctness and maintainability issues that may cause incorrect exports or failures.

Request changes.
EOF

gh pr review "$PR_NUM" --request-changes --body-file "$REVIEW_FILE"

rm -f "$REVIEW_FILE"
