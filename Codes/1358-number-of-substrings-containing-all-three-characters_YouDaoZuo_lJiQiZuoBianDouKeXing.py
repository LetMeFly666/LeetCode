'''
Author: LetMeFly
Date: 2026-07-01 15:48:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-01 15:49:11
'''
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans = 0
        cnt = [0, 0, 0]
        l = 0
        for r in range(len(s)):
            cnt[ord(s[r]) - ord('a')] += 1
            while cnt[0] and cnt[1] and cnt[2]:
                cnt[ord(s[l]) - ord('a')] -= 1
                l += 1
            ans += l
        return ans
