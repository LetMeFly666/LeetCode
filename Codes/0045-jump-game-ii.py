'''
Author: LetMeFly
Date: 2025-01-27 07:48:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-27 07:55:15
'''
from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = nowMax = nextMax = 0
        for i, l in enumerate(nums[:-1]):
            nextMax = max(nextMax, i + l)
            if i == nowMax:
                nowMax = nextMax
                ans += 1
        return ans

if __name__ == '__main__':
    sol = Solution()
    ans = sol.jump([2, 3, 1, 1, 4])
    print(ans)
    assert ans == 2