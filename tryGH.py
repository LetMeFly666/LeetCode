'''
Author: LetMeFly
Date: 2025-04-14 00:20:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-14 00:26:53
'''
import os
num = 192
num = 1922

issueTitle = f'Who can add 1 more problem of LeetCode {num}'
alreadyRelatedIssueLists = os.popen(f'gh issue list --search "{issueTitle}"').read()
alreadyRelatedIssueListsSplited = alreadyRelatedIssueLists.split('\n')
print(alreadyRelatedIssueLists)
print(alreadyRelatedIssueListsSplited)
issueNum = 0
for line in alreadyRelatedIssueListsSplited:
    if issueTitle in line:
        issueNum = int(line.split()[0])
print(issueNum)