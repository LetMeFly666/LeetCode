'''
Author: LetMeFly
Date: 2025-10-23 23:05:13
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-23 23:28:23
'''
class Solution:
    def hasSameDigits(self, s: str) -> bool:
        a = list(map(lambda c: ord(c) - ord('0'), s))
        while len(a) > 2:
            b = [0] * (len(a) - 1)
            for i in range(len(a) - 1):
                b[i] = (a[i] + a[i + 1]) % 10
            a = b
        return a[0] == a[1]