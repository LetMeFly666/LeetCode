'''
Author: LetMeFly
Date: 2023-08-16 08:29:31
LastEditors: LetMeFly
LastEditTime: 2023-08-16 08:43:30
'''
from typing import List

class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        visited = [False] * n
        who, th = 0, 0
        while not visited[who]:
            visited[who] = True
            th += 1
            who = (who + th * k) % n
        ans = []
        for i in range(n):
            if not visited[i]:
                ans.append(i + 1)
        return ans