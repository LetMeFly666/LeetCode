'''
Author: LetMeFly
Date: 2025-01-30 08:18:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-30 08:20:54
'''
from typing import List
from collections import Counter

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cnt = Counter(nums1)
        ans = []
        for t in nums2:
            if cnt[t]:
                ans.append(t)
                cnt[t] -= 1
        return ans