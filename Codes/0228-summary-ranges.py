'''
Author: LetMeFly
Date: 2023-08-26 09:24:24
LastEditors: LetMeFly
LastEditTime: 2023-08-26 09:34:24
'''
from typing import List

class Solution:
    def genStr(self, l: int, r: int) -> str:
        if l == r:
            return str(l)
        return str(l) + '->' + str(r)
    
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        ans = []
        beginNum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] !=  nums[i - 1] + 1:
                ans.append(self.genStr(beginNum, nums[i - 1]))
                beginNum = nums[i]
        ans.append(self.genStr(beginNum, nums[-1]))
        return ans