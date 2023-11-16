'''
Author: LetMeFly
Date: 2023-11-16 20:05:02
LastEditors: LetMeFly
LastEditTime: 2023-11-16 20:07:10
'''
from typing import List

class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans = 0
        nowCnt = 0
        for i in range(len(nums)):
            if nowCnt:
                if nums[i] <= threshold and nums[i] % 2 != nums[i - 1] % 2:
                    nowCnt += 1
                else:
                    ans = max(ans, nowCnt)
                    nowCnt = 0
            if not nowCnt:
                if nums[i] <= threshold and nums[i] % 2 == 0:
                    nowCnt = 1
        return max(ans, nowCnt)
