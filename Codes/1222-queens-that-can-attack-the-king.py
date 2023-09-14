'''
Author: LetMeFly
Date: 2023-09-14 09:59:51
LastEditors: LetMeFly
LastEditTime: 2023-09-14 10:10:33
'''
from typing import List

class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        se = set(map(tuple, queens))
        ans = []
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                if not dx and not dy:
                    continue
                nowX, nowY = king
                while 0 <= nowX + dx < 8 and 0 <= nowY + dy < 8:
                    nowX, nowY = nowX + dx, nowY + dy
                    if (nowX, nowY) in se:
                        ans.append([nowX, nowY])
                        break
        return ans