'''
Author: LetMeFly
Date: 2025-06-26 22:16:30
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-26 22:38:54
'''
class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans, val, k_length = 0, 0, k.bit_length()
        for i, c in enumerate(s[::-1]):
            if c == '0':
                ans += 1
                continue
            if i < k_length and val + (1 << i) <= k:
                ans += 1
                val += 1 << i
        return ans