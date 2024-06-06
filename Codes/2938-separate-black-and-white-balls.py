'''
Author: LetMeFly
Date: 2024-06-06 22:40:13
LastEditors: LetMeFly
LastEditTime: 2024-06-06 22:40:50
'''
class Solution:
    def minimumSteps(self, s: str) -> int:
        ans, times = 0, 0
        for c in s:
            if c == '1':
                times += 1
            else:
                ans += times
        return ans