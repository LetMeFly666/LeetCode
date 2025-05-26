'''
Author: LetMeFly
Date: 2025-05-26 22:02:44
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-26 23:34:26
'''
from typing import List

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        out = [[] for _ in range(len(colors))]
        indegree = [0] * len(colors)
        for x, y in edges:
            out[x].append(y)
            indegree[y] += 1
        q = []
        for i in range(len(colors)):
            if indegree[i] == 0:
                q.append(i)
        dp = [[0] * 26 for _ in range(len(colors))]
        ans = 0
        while q:
            thisNode = q.pop()
            dp[thisNode][ord(colors[thisNode]) - ord('a')] += 1
            ans = max(ans, dp[thisNode][ord(colors[thisNode]) - ord('a')])
            for nextNode in out[thisNode]:
                indegree[nextNode] -= 1
                if not indegree[nextNode]:
                    q.append(nextNode)
                for i in range(26):
                    dp[nextNode][i] = max(dp[nextNode][i], dp[thisNode][i])
        if any(indegree):
            return -1
        return ans
