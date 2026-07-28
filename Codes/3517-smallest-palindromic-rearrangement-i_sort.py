'''
Author: LetMeFly
Date: 2026-07-28 21:42:17
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-28 21:46:51
'''
class Solution:
    def smallestPalindrome(self, s: str) -> str:
        t = sorted(s[: len(s) // 2])
        return ''.join(t) + (s[len(s) // 2] if len(s) % 2 else '') + ''.join(reversed(t))
