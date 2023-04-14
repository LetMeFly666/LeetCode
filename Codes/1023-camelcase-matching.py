'''
Author: LetMeFly
Date: 2023-04-14 13:41:20
LastEditors: LetMeFly
LastEditTime: 2023-04-14 13:54:31
'''
from typing import List

class Solution:
    def isOK(self, q: str, pattern: str) -> bool:
        locP = 0
        for c in q:
            if locP < len(pattern) and pattern[locP] == c:
                locP += 1
            elif c.isupper():
                return False
        return locP == len(pattern)

    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        ans = [False] * len(queries)
        for i in range(len(queries)):
            ans[i] = self.isOK(queries[i], pattern)
        return ans