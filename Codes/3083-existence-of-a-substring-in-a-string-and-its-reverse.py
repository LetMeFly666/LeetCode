'''
Author: LetMeFly
Date: 2024-12-26 15:40:00
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-26 15:41:59
'''
class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        visited = [[False] * 26 for _ in range(26)]
        for i in range(1, len(s)):
            visited[ord(s[i - 1]) - ord('a')][ord(s[i]) - ord('a')] = True
            if visited[ord(s[i]) - ord('a')][ord(s[i - 1]) - ord('a')]:
                return True
        return False