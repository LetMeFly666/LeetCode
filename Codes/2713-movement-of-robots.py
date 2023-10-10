from typing import List

MOD = int(1e9 + 7)
class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n = len(s)
        for i in range(n):
            if s[i] == 'L':
                nums[i] -= d
            else:
                nums[i] += d
        ans = 0
        nums.sort()
        for i in range(1, n):
            ans = (ans + i * (n - i) * (nums[i] - nums[i - 1])) % MOD
        return ans
