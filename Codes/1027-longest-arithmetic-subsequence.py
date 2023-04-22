'''
Author: LetMeFly
Date: 2023-04-22 09:42:46
LastEditors: LetMeFly
LastEditTime: 2023-04-22 09:49:42
'''
from typing import List

class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        ans = 2
        diff = max(nums) - min(nums)
        for d in range(-diff, diff + 1):
            mp = dict()
            for num in nums:
                if num - d in mp:
                    thisAns = mp[num - d] + 1
                else:
                    thisAns = 1
                mp[num] = thisAns
                ans = max(ans, thisAns)
        return ans