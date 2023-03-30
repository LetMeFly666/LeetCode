'''
Author: LetMeFly
Date: 2023-03-30 09:06:42
LastEditors: LetMeFly
LastEditTime: 2023-03-30 09:17:31
'''
# from typing import List
# from collections import OrderedDict


if False:  # Error: python set是无序的！！！
    class Solution:
        def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
            se = set()
            for point in points:
                se.add(point[0])
            ans = 0
            last = se.pop()
            for t in se:
                ans = min(ans, t - last)
                last = t
            return ans


from typing import List

class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        x = [p[0] for p in points]
        x.sort()
        return max(x[i] - x[i - 1] for i in range(1, len(x)))