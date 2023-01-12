'''
Author: LetMeFly
Date: 2023-01-12 22:23:47
LastEditors: LetMeFly
LastEditTime: 2023-01-12 22:40:28
'''
from typing import List

if False:
    class Solution:
        def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
            ma = {}
            for v in knowledge:
                ma[v[0]] = v[1]
            ans = ""
            for i in range(0, len(s)):  # 不可，因为下面对i的更改无法作用到这里
                if (s[i] == '('):
                    to = i + 1
                    while s[to] != ')':
                        to += 1
                    ans += ma.get(s[i + 1 : to])
                    i = to
                else:
                    ans += s[i]
            return ans

# True
class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        ma = {}
        for v in knowledge:
            ma[v[0]] = v[1]
        ans = ""
        i = 0
        while i < len(s):
            if (s[i] == '('):
                to = i + 1
                while s[to] != ')':
                    to += 1
                ans += ma.get(s[i + 1 : to], "?")
                i = to
            else:
                ans += s[i]
            i += 1
        return ans
