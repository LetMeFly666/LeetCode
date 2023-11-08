'''
Author: LetMeFly
Date: 2023-11-08 19:07:14
LastEditors: LetMeFly
LastEditTime: 2023-11-08 19:08:34
'''
class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans, index = 0, 0
        while index < len(s):
            cnt0, cnt1 = 0, 0
            while index < len(s) and s[index] == '0':
                cnt0, index = cnt0 + 1, index + 1
            while index < len(s) and s[index] == '1':
                cnt1, index = cnt1 + 1, index + 1
            ans = max(ans, 2 * min(cnt0, cnt1))
        return ans