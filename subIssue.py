'''
Author: LetMeFly
Date: 2025-07-28 23:06:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-28 23:52:38
'''
import subprocess
import json

# gh issue view 1032 --json linkedIssues

# 配置
OWNER = "LetMeFly666"
REPO = "LeetCode"
PARENT_ISSUE_NUMBER = 1032

# GraphQL 查询
query = f"""
query {{
  repository(owner: "{OWNER}", name: "{REPO}") {{
    issue(number: {PARENT_ISSUE_NUMBER}) {{
      childIssues: linkedIssues(first: 100, linkTypes: [CHILD]) {{
        nodes {{
          number
          state
        }}
      }}
    }}
  }}
}}
"""

# 调用 gh api
cmd = f'gh api graphql -f query="{query}"'
result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
data = json.loads(result.stdout)
print(data)

# 提取数据
child_issues = data["data"]["repository"]["issue"]["childIssues"]["nodes"]
total = len(child_issues)
closed = sum(1 for issue in child_issues if issue["state"] == "CLOSED")
open = total - closed

print(f"Total child issues: {total}")
print(f"Closed: {closed}")
print(f"Open: {open}")