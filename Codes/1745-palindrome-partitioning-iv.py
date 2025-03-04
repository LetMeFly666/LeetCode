'''
Author: LetMeFly
Date: 2025-03-04 10:30:23
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-04 10:33:30
'''
class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        isok = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                isok[i][j] = s[i] == s[j] and isok[i + 1][j - 1]
        for i in range(n):
            for j in range(i + 1, n - 1):
                if isok[0][i] and isok[i + 1][j] and isok[j + 1][n - 1]:
                    return True
        return False