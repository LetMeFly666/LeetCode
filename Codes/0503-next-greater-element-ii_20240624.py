'''
Author: LetMeFly
Date: 2024-06-24 12:49:19
LastEditors: LetMeFly
LastEditTime: 2024-06-24 12:51:02
'''
from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        ans = [-1] * len(nums)
        st = []
        for i in range(len(nums) * 2):
            th = i % len(nums)
            while st and nums[st[-1]] < nums[th]:
                ans[st.pop()] = nums[th]
            st.append(th)
        return ans