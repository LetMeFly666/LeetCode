'''
Author: LetMeFly
Date: 2024-06-26 17:18:49
LastEditors: LetMeFly
LastEditTime: 2024-06-26 22:26:19
超时了。。。
'''
from typing import List

MOD = 1_000_000_007

class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0 for _ in range(n)] for __ in range(1 << n)]
        for i in range(n):
            dp[1 << i][i] = 1
        for state in range(1 << n):
            for last in range(n):
                for prev in range(n):
                    if (state & (1 << last)) and (state & (1 << prev)) and (nums[prev] % nums[last] == 0 or nums[last] % nums[prev] == 0):
                        dp[state][last] = (dp[state][last] + dp[state ^ (1 << last)][prev]) % MOD
        ans = 0
        for i in range(n):
            ans = (ans + dp[(1 << n) - 1][i]) % MOD
        return ans


if __name__ == '__main__':
    print(Solution.specialPerm('', [838335396, 241654240, 937115884, 795934157, 907282921, 71642053, 242720010, 16417709, 706807579, 752842522, 162230770, 425078819, 793563691, 522087056]))