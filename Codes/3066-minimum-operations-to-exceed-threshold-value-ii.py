'''
Author: LetMeFly
Date: 2025-01-15 14:02:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-15 14:12:18
'''
from typing import List
import heapq

"""
# FirstTry - RE
# python的heappop会直接缩短列表长度而不是丢到列表尾部
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        heapq.heapify(nums)
        while nums[0] < k:
            x = nums[0]
            heapq.heappop(nums[:-ans]) if ans else heapq.heappop(nums)  # nums[:-0]为[]
            y = nums[0]
            heapq.heappop(nums[:-ans - 1])
            heapq.heappush(nums[:-ans - 1], 2 * min(x, y) + max(x, y))
            ans += 1
        return ans
"""

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        heapq.heapify(nums)
        while nums[0] < k:
            x = nums[0]
            heapq.heappop(nums)
            y = nums[0]
            heapq.heappop(nums)
            heapq.heappush(nums, 2 * min(x, y) + max(x, y))
            ans += 1
        return ans

if __name__ == '__main__':
    sol = Solution()
    print(sol.minOperations([2, 11, 10, 1, 3], 10))