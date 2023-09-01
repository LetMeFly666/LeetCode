'''
Author: LetMeFly
Date: 2023-09-01 09:34:50
LastEditors: LetMeFly
LastEditTime: 2023-09-01 09:36:33
'''
class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        if cost1 > cost2:
            cost1, cost2 = cost2, cost1
        ans = 0
        M2 = total // cost2
        for i in range(M2 + 1):
            ans += (total - i * cost2) // cost1 + 1
        return ans