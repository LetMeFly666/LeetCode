'''
Author: LetMeFly
Date: 2024-05-24 21:28:18
LastEditors: LetMeFly
LastEditTime: 2024-05-24 21:28:24
'''
from typing import List

class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        st = []
        for i in range(len(nums)):
            while st and st[-1] > nums[i] and (len(st) - 1) + (len(nums) - i) >= k:
                st.pop()
            if len(st) < k:
                st.append(nums[i])
        return st