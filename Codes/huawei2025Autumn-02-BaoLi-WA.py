'''
Author: LetMeFly
Date: 2025-10-29 20:05:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-29 20:59:46
'''
"""
dp[i][j]：重量i价值j最少车数


5
80
30 45 15 15 80
400 470 200 200 870
"""

n = int(input())
k = int(input())
weights = list(map(int, input().split()))
values = list(map(int, input().split()))

dp = [[0] * (n * 1000) for _ in range(n)]
maxVal = 0
ans = []
status = 1 << n
for i in range(status):
    thisW = thisV = 0
    thisChoosen = []
    for j in range(n):
        if i & (1 << j):
            thisW += weights[j]
            thisV += values[j]
            thisChoosen.append(j)
            if thisW > k:
                break
    if thisW > k:
        break
    if thisW <= k:
        if thisV > maxVal or (thisV == maxVal and len(thisChoosen) < len(ans)):
        # if thisV > maxVal:
            ans = thisChoosen
            maxV = thisV

if not len(ans):
    print(-1)
else:
    ans.sort()
    for i, v in enumerate(ans):
        # print(v, end=' ')
        if i:
            print(' ', end='')
        print(v, end='')


# """
# dfs(i)
# """