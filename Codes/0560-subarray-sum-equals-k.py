'''
Author: LetMeFly
Date: 2023-03-15 10:15:03
LastEditors: LetMeFly
LastEditTime: 2023-03-15 10:31:26
'''
from collections import defaultdict
from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        ma = defaultdict(int)
        ma[0] = 1
        cnt = 0
        for n in nums:
            cnt += n
            if cnt - k in ma:
                ans += ma[cnt - k]
            ma[cnt] += 1
        return ans