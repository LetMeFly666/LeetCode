'''
Author: LetMeFly
Date: 2026-02-19 11:16:44
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-19 11:33:22
'''
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        ans = lastCnt = 0
        cnt = 1
        for i in range(1, len(s) + 1):
            if i == len(s) or s[i] != s[i - 1]:
                ans += min(lastCnt, cnt)
                lastCnt = cnt
                cnt = 0
            cnt += 1
        return ans
                