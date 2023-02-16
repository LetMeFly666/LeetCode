'''
Author: LetMeFly
Date: 2023-02-16 09:32:02
LastEditors: LetMeFly
LastEditTime: 2023-02-16 09:38:13
'''
from typing import List


class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        se = set()
        cntPair = 0
        for i in nums:
            if i in se:
                se.remove(i)
                cntPair += 1
            else:
                se.add(i)
        return [cntPair, len(nums) - cntPair * 2]