'''
Author: LetMeFly
Date: 2026-02-26 23:55:52
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-26 23:59:25
'''
"""
1101
1110
111
1000
100
10
1
"""
class Solution:
    def numSteps(self, s: str) -> int:
        a = int(s, 2)
        ans = 0
        while a != 1:
            if a % 2:
                a += 1
            else:
                a //= 2
            ans += 1
            # print(a)
        return ans

# print(Solution.numSteps('', '1101'))
