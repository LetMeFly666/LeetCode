'''
Author: LetMeFly
Date: 2023-11-26 18:28:37
LastEditors: LetMeFly
LastEditTime: 2023-11-26 18:30:46
'''
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        pos = [[-1] for _ in range(26)]
        for i in range(len(s)):
            pos[ord(s[i]) - ord('A')].append(i)
        for i in range(26):
            pos[i].append(len(s))
        ans = 0
        for i in range(26):
            for j in range(1, len(pos[i]) - 1):
                ans += (pos[i][j] - pos[i][j - 1]) * (pos[i][j + 1] - pos[i][j])
        return ans