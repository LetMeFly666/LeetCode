'''
Author: LetMeFly
Date: 2024-11-12 18:14:40
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-12 18:29:13
'''
from typing import List

class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        cnt = [0, 0]
        ans = 0
        l = 0
        for r in range(len(s)):
            cnt[ord(s[r]) - ord('0')] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[ord(s[l]) - ord('0')] -= 1
                l += 1
            ans += r - l + 1
        return ans
