'''
Author: LetMeFly
Date: 2024-09-19 17:52:13
LastEditors: LetMeFly
LastEditTime: 2024-09-19 17:53:34
'''
class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        nowCnt, ans = 1, 1
        for i in range(1, len(s)):
            if ord(s[i]) == ord(s[i - 1]) + 1:
                nowCnt += 1
                ans = max(ans, nowCnt)
            else:
                nowCnt = 1
        return ans