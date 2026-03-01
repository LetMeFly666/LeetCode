#!/bin/bash
###
 # @Author: LetMeFly
 # @Date: 2026-03-01 13:41:10
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-03-01 13:41:12
### 
set -euo pipefail

# 参数配置
OWNER="LetMeFly666"
REPO="LeetCode"
PR_NUMBER=1412
COMMIT_ID="1c489724e0716cd038e746f3e15a62906054eaca"

# 使用gh api提交PR review
echo "Submitting PR review with inline suggestions using gh api..."

# 创建临时文件存储payload
PAYLOAD_FILE=$(mktemp /tmp/review_payload_XXXX.json)

cat > "$PAYLOAD_FILE" << 'REVIEW_JSON'
{
  "commit_id": "1c489724e0716cd038e746f3e15a62906054eaca",
  "body": "## PR 概要\n\n本 PR 为 LeetCode 1356（根据数字二进制下1的数目排序）添加了 C++ 题解代码和 Markdown 题解文档，同时在 README 索引表中新增了对应条目，并在英语学习笔记中添加了新单词 \"kneel\"。总计变更 5 个文件，+124/-1 行。\n\n## 代码正确性分析\n\n| 文件 | 变更类型 | 正确性 | 说明 |\n|------|---------|--------|------|\n| `Codes/1356-sort-integers-by-the-number-of-1-bits_20260225.cpp` | 新增 | ✅ 正确 | 使用 `__builtin_popcount` + 自定义排序，逻辑正确 |\n| `Solutions/LeetCode 1356.根据数字二进制下1的数目排序.md` | 新增 | ✅ 正确 | 题解文档结构完整，代码与 Codes 目录一致 |\n| `README.md` | 修改 | ✅ 正确 | 新增一行索引，格式与已有条目一致 |\n| `.commitmsg` | 修改 | ✅ 正确 | 更新 commit 元信息 |\n| `Solutions/Other-English-LearningNotes-SomeWords.md` | 修改 | ⚠️ 有格式问题 | 新增单词 \"kneel\"，但多出一行裸文本 `这劲儿着呀` 破坏表格结构 |\n\n## 潜在问题与建议\n\n### P2: 英语笔记表格格式被破坏\n\n`Other-English-LearningNotes-SomeWords.md` 第 1840 行 `这劲儿着呀` 是一行裸文本，不在 Markdown 表格内。这会导致表格在该行截断，后续内容不再被渲染为表格行。建议删除或移入表格释义列。\n\n### P3: Lambda 比较器参数建议使用 `const` 引用\n\n`1356-sort-integers-by-the-number-of-1-bits_20260225.cpp` 第 14 行 lambda 使用 `int&` 引用作为 `sort` 比较器参数。标准库要求比较器不应修改元素，使用 `const int&` 更符合规范，且能让编译器帮助检查意外修改。\n\n## 总结\n\n| 维度 | 评级 | 说明 |\n|------|------|------|\n| 代码正确性 | ⭐⭐⭐⭐⭐ | 排序逻辑正确，解题思路清晰 |\n| 代码风格 | ⭐⭐⭐⭐ | 建议 lambda 参数加 `const` |\n| 文档质量 | ⭐⭐⭐⭐ | 题解完整，英语笔记有小格式问题 |\n| 一致性 | ⭐⭐⭐⭐⭐ | README/题解/代码三处一致 |\n\n## 最终合并建议\n\n**建议合并 (Approve)**。核心代码正确无误，仅有一处笔记格式问题（P2）和一处编码风格建议（P3），均不影响功能。可在后续提交中修复。\n\n> *Review by AI Assistant*",
  "event": "COMMENT",
  "comments": [
    {
      "path": "Codes/1356-sort-integers-by-the-number-of-1-bits_20260225.cpp",
      "line": 14,
      "side": "RIGHT",
      "body": "**P3 (建议)**: lambda 参数使用 `int&` 引用类型，但 `std::sort` 的比较器参数通常应为 `const` 引用（`const int&`）或值传递。虽然此处对正确性无影响，但使用 `const` 更符合规范，能避免意外修改元素。\n\n```suggestion\n sort(arr.begin(), arr.end(), [](const int& a, const int& b) {\n```"
    },
    {
      "path": "Solutions/Other-English-LearningNotes-SomeWords.md",
      "line": 1840,
      "side": "RIGHT",
      "body": "**P2 (格式问题)**: 这一行 `这劲儿着呀` 不在表格内，破坏了 Markdown 表格结构。如果这是对 \"kneel\" 的个人备注，建议放入表格的释义列中，或者删除此行。\n\n```suggestion\n```"
    }
  ]
}
REVIEW_JSON

# 使用gh api提交review
echo "Executing: gh api -X POST /repos/$OWNER/$REPO/pulls/$PR_NUMBER/reviews -f \"commit_id=$COMMIT_ID\" --input $PAYLOAD_FILE"
gh api -X POST "/repos/$OWNER/$REPO/pulls/$PR_NUMBER/reviews" --input "$PAYLOAD_FILE"

# 清理临时文件
rm -f "$PAYLOAD_FILE"

echo "Review submitted successfully using gh api!"