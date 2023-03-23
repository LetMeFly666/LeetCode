'''
Author: LetMeFly
Date: 2023-03-23 17:00:27
LastEditors: LetMeFly
LastEditTime: 2023-03-23 18:03:14
'''
from typing import List

class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        ans = [False for i in range(len(l))]
        for i in range(len(l)):
            m = min(nums[l[i] : r[i] + 1])
            M = max(nums[l[i] : r[i] + 1])
            if m == M:
                ans[i] = True
                continue
            if (M - m) % (r[i] - l[i]):
                ans[i] = False
                continue
            d = (M - m) // (r[i] - l[i])
            se = set()
            ok = True
            for j in range(l[i], r[i] + 1):
                if nums[j] in se:
                    ok = False
                    break
                if (nums[j] - m) % d:
                    ok = False
                    break
                se.add(nums[j])
            ans[i] = ok
        return ans