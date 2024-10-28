'''
Author: LetMeFly
Date: 2024-10-26 09:43:01
LastEditors: LetMeFly
LastEditTime: 2024-10-28 21:27:48
'''
from typing import List

class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        dp = [False] * (rewardValues[-1] * 2)
        dp[0] = True
        for x in rewardValues:  # [0, x - 1] + x -> [x, 2x - 1]
            for i in range(x, 2 * x):  # 这里面任意一个i加上一次x后就会>2x，因此x不会被计算两次
                dp[i] |= dp[i - x]
        ans = len(dp) - 1
        while not dp[ans]:
            ans -= 1
        return ans