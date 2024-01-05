'''
Author: LetMeFly
Date: 2024-01-05 19:01:29
LastEditors: LetMeFly
LastEditTime: 2024-01-05 19:03:14
'''
from typing import List

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        ans = [0] * len(heights)
        st = []
        for i in range(len(heights) - 1, -1, -1):
            while st and heights[st[-1]] < heights[i]:
                st.pop()
                ans[i] += 1
            if st:
                ans[i] += 1
            st.append(i)
        return ans