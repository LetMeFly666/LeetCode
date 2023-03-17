'''
Author: LetMeFly
Date: 2023-03-17 12:58:57
LastEditors: LetMeFly
LastEditTime: 2023-03-17 13:05:38
'''
from typing import List
import bisect


class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        for i, q in enumerate(queries):  # 这里for q in queries的话，修改q是不会修改queries中的值的
            queries[i] = bisect.bisect_right(nums, q)
        return queries