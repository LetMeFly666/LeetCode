'''
Author: LetMeFly
Date: 2023-07-12 08:44:02
LastEditors: LetMeFly
LastEditTime: 2023-07-12 08:48:18
'''
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        s = str(n)
        return sum((-1 if i % 2 else 1) * (ord(s[i]) - ord('0')) for i in range(len(s)))