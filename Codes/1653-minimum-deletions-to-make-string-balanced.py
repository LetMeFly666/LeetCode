'''
Author: LetMeFly
Date: 2023-03-06 12:03:32
LastEditors: LetMeFly
LastEditTime: 2023-03-06 12:05:15
'''
class Solution:
    def minimumDeletions(self, s: str) -> int:
        fontB = 0
        backA = s.count('a')
        ans = len(s) - 1
        for i in range(len(s) + 1):
            ans = min(ans, backA + fontB)
            if i < len(s):
                if s[i] == 'a':
                    backA -= 1
                else:
                    fontB += 1
        return ans