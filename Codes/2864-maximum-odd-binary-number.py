'''
Author: LetMeFly
Date: 2024-03-13 08:39:15
LastEditors: LetMeFly
LastEditTime: 2024-03-13 08:40:27
'''
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt1 = sum(1 if c == '1' else 0 for c in s)
        return '1' * (cnt1 - 1) + '0' * (len(s) - cnt1) + '1'
