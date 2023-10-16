from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        temp = 0
        for t in nums:
            temp ^= t
        mask = temp & (-temp)
        ans = [0, 0]
        for t in nums:
            nums[(t & mask) != 0] ^= t
        return ans