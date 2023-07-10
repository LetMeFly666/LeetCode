'''
Author: LetMeFly
Date: 2023-07-10 08:52:04
LastEditors: LetMeFly
LastEditTime: 2023-07-10 09:11:51
'''
from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = sum(nums[:3])
        n = len(nums)
        nums.sort()
        for i in range(n):
            finding = target - nums[i]
            l, r = i + 1, n - 1
            while l < r:
                diff = finding - nums[l] - nums[r]
                if diff == 0:
                    return target
                elif diff > 0:
                    l += 1
                else:
                    r -= 1
                if abs(diff) < abs(ans - target):
                    ans = target - diff
        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.threeSumClosest([2,3,8,9,10], 16))
