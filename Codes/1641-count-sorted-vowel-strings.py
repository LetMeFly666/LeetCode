'''
Author: LetMeFly
Date: 2023-03-29 10:24:03
LastEditors: LetMeFly
LastEditTime: 2023-03-29 11:04:31
'''
if False:  # FirstTry: dp: 小复杂的dp
    class Solution:
        def countVowelStrings(self, n: int) -> int:
            dp = [1 for _ in range(5)]
            for i in range(2, n + 1):
                newDp = [0 for _ in range(5)]
                for j in range(5):
                    for k in range(0, j + 1):
                        newDp[j] += dp[k]
                dp = newDp
            return sum(dp)


if False:  # SecondTry: dp: 小简化
    class Solution:
        def countVowelStrings(self, n: int) -> int:
            dp = [1 for _ in range(5)]
            for i in range(2, n + 1):
                for j in range(1, 5):
                    dp[j] += dp[j - 1]
            return sum(dp)


# ThirdTry: 排列组合
from math import comb
class Solution:
    def countVowelStrings(self, n: int) -> int:
        return comb(n + 4, 4)