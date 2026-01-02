'''
Author: LetMeFly
Date: 2026-01-02 17:13:12
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-02 17:19:56
'''
from typing import List
from random import randint

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums) - 1
        while True:
            loc1 = randint(0, n)
            loc2 = randint(0, n)
            # print(loc1, loc2)
            if loc1 != loc2 and nums[loc1] == nums[loc2]:
                return nums[loc1]


# if __name__ == '__main__':
#     sol = Solution()
#     print(sol.repeatedNTimes([1,2,3,3]))