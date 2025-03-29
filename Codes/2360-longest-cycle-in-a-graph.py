'''
Author: LetMeFly
Date: 2025-03-29 14:06:24
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-29 14:09:27
'''
from typing import List

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        ans = -1
        cnt = 1
        visited = [0] * len(edges)
        for i in range(len(edges)):
            begin = cnt
            while edges[i] != -1 and not visited[i]:
                visited[i] = cnt
                cnt += 1
                i = edges[i]
            if edges[i] != -1 and visited[i] >= begin:
                ans = max(ans, cnt - visited[i])
        return ans