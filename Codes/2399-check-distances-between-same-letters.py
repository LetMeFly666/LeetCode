'''
Author: LetMeFly
Date: 2023-04-09 09:43:56
LastEditors: LetMeFly
LastEditTime: 2023-04-09 09:48:23
'''
from typing import List

class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        for i in range(len(s)):
            if distance[ord(s[i]) - ord('a')] != -1:
                should = i + distance[ord(s[i]) - ord('a')] + 1
                if should >= len(s) or s[should] != s[i]:
                    return False
                distance[ord(s[i]) - ord('a')] = -1
        return True