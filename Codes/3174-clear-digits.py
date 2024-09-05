'''
Author: LetMeFly
Date: 2024-09-05 09:30:56
LastEditors: LetMeFly
LastEditTime: 2024-09-05 09:38:01
'''
class Solution:
    def clearDigits(self, s: str) -> str:
        ans = []
        cntDigit = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i].isdigit():
                cntDigit += 1
            elif cntDigit:
                cntDigit -= 1
            else:
                ans.append(s[i])
        return ''.join(reversed(ans))