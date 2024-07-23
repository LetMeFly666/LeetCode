'''
Author: LetMeFly
Date: 2024-07-22 23:53:16
LastEditors: LetMeFly
LastEditTime: 2024-07-23 00:00:18
'''
from typing import List

class Solution:
    def dfs(self, x: int) -> int:
        self.visited[x] = True
        ans = 1
        for nextNode in self.graph[x]:
            if not self.visited[nextNode]:
                ans += self.dfs(nextNode)
        return ans

    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        self.graph = [[] for _ in range(len(bombs))]
        for i in range(len(bombs)):
            for j in range(i + 1, len(bombs)):
                d2 = (bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1])
                if d2 <= bombs[i][2] * bombs[i][2]:  # i能炸j
                    self.graph[i].append(j)
                if d2 <= bombs[j][2] * bombs[j][2]:
                    self.graph[j].append(i)
        
        ans = 1
        for i in range(len(bombs)):
            self.visited = [False] * len(bombs)
            ans = max(ans, self.dfs(i))
        return ans
