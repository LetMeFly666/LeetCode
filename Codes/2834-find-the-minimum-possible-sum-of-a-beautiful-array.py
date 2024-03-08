'''
Author: LetMeFly
Date: 2024-03-08 16:12:10
LastEditors: LetMeFly
LastEditTime: 2024-03-08 16:16:16
'''
MOD = int(1e9) + 7
class Solution:
    def cal(self, l: int, r: int) -> int:
        return (l + r) * (r - l + 1) // 2

    def minimumPossibleSum(self, n: int, target: int) -> int:
        half = target >> 1
        if n <= half:
            return self.cal(1, n)
        return (self.cal(1, half) + self.cal(target, target + n - half - 1)) % MOD


# sol = Solution()
# print(sol.minimumPossibleSum(2, 3))
