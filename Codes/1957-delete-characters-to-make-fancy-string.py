'''
Author: LetMeFly
Date: 2025-07-21 18:48:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-21 18:54:53
'''
class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = []
        last = '0'
        cnt = 0
        for c in s:
            if c != last:
                last = c
                cnt = 0
            cnt += 1
            if cnt < 3:
                ans.append(c)
        return ''.join(ans)