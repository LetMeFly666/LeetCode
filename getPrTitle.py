'''
Author: LetMeFly
Date: 2025-12-24 09:54:26
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-25 21:36:27
'''
import subprocess
import json

pr_number = 1278  # PR 号

result = subprocess.run(
    ["gh", "pr", "view", str(pr_number), "--json", "title"],
    capture_output=True,
    text=True,
    check=True,
    encoding="utf-8",
)

title = json.loads(result.stdout)["title"]
print(title)


issue_number = 1279
result = subprocess.run(
    ["gh", "issue", "view", str(issue_number), "--json", "title"],
    capture_output=True,
    text=True,
    check=True,
    encoding="utf-8",
)

title = json.loads(result.stdout)["title"]
print(title)