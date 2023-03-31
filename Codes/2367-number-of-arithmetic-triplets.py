'''
Author: LetMeFly
Date: 2023-03-31 09:00:19
LastEditors: LetMeFly
LastEditTime: 2023-03-31 09:25:17
'''
if False:  # FirstTry  # 哈希
    from typing import List


    class Solution:
        def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
            se = set()
            for t in nums:
                se.add(t)
            ans = 0
            for t in nums:
                ans += t + diff in se and t + 2 * diff in se
            return ans


# SecondTry  # 三指针
from typing import List


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        ans, i, j = 0, 0, 0
        for k in range(len(nums)):
            while nums[j] + diff < nums[k]:
                j += 1
            if nums[j] + diff > nums[k]:
                continue
            while nums[i] + diff < nums[j]:
                i += 1
            if nums[i] + diff == nums[j]:
                ans += 1
        return ans