'''
Author: LetMeFly
Date: 2023-11-18 11:23:07
LastEditors: LetMeFly
LastEditTime: 2023-11-18 11:26:28
'''
from typing import List

class Solution:
    def getSum(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
    
    def maximumSum(self, nums: List[int]) -> int:
        ans = -1
        ma = dict()
        for t in nums:
            s = self.getSum(t)
            if s in ma:
                if t > ma[s][1]:
                    ma[s][1] = t
                if ma[s][0] < ma[s][1]:
                    ma[s][0], ma[s][1] = ma[s][1], ma[s][0]
                ans = max(ans, sum(ma[s]))
            else:
                ma[s] = [t, 0]
        return ans