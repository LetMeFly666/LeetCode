'''
Author: LetMeFly
Date: 2025-03-14 09:34:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-14 09:34:04
'''
class Solution:
    def isBalanced(self, num: str) -> bool:
        cnt = 0
        for i, c in enumerate(num):
            cnt += ord(c) - 48 if i % 2 else 48 - ord(c)
        return cnt == 0