'''
Author: LetMeFly
Date: 2025-10-11 18:10:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-11 19:04:17
'''
from typing import List
from collections import Counter

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        values = sorted(cnt)
        dp0 = dp1 = dp2 = 0
        val1 = val2 = -10
        for val in values:
            valSum = val * cnt[val]
            if val - val2 > 2:  # 无冲突
                useThis = valSum + dp2
            elif val - val1 > 2:  # 和val2相差小于2，但和val1不冲突
                useThis = valSum + dp1
            else:  # 和val1、val2都冲突(一定不会再和前面的冲突了)
                useThis = valSum + dp0
            dp = max(useThis, dp2)
            dp0, dp1, dp2 = dp1, dp2, dp
            val1, val2 = val2, val
        return dp2