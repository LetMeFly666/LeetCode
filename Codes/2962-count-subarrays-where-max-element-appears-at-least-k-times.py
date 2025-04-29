'''
Author: LetMeFly
Date: 2025-04-29 13:19:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-29 21:21:03
'''
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        l = cnt = ans = 0
        for t in nums:
            cnt += t == mx
            while cnt == k:
                cnt -= nums[l] == mx
                l += 1
            ans += l
        return ans