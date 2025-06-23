'''
Author: LetMeFly
Date: 2025-06-22 12:43:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-22 20:55:30
'''
from typing import List

# 'a' * -1 -> ''
# [1, 2][1:100] -> [2]
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [s[i:i+k] + fill * (k - (len(s) - i)) for i in range(0, len(s), k)]