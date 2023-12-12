'''
Author: LetMeFly
Date: 2023-12-12 20:49:52
LastEditors: LetMeFly
LastEditTime: 2023-12-12 20:53:22
'''
from typing import List

class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        ans = [-1] * len(nums)
        st1 = []
        st2 = []
        for i in range(len(nums)):
            while st2 and nums[st2[-1]] < nums[i]:
                ans[st2[-1]] = nums[i]
                st2.pop()
            temp = []
            while st1 and nums[st1[-1]] < nums[i]:
                temp.append(st1[-1])
                st1.pop()
            st1.append(i)
            temp.reverse()
            st2 += temp
        return ans