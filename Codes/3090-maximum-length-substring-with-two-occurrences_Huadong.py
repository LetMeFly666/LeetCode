'''
Author: LetMeFly
Date: 2026-08-14 09:42:40
LastEditors: LetMeFly.xyz
LastEditTime: 2026-08-14 09:44:21
'''
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        ans = 0
        l = r = 0
        cnt = [0] * 26
        for r in range(len(s)):
            th = ord(s[r]) - 97
            cnt[th] += 1
            while cnt[th] > 2:
                cnt[ord(s[l]) - 97] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans
