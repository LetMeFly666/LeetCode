'''
Author: LetMeFly
Date: 2024-08-24 12:25:18
LastEditors: LetMeFly
LastEditTime: 2024-08-24 12:25:19
'''
class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        ans = 0
        for i in range(len(s)):
            ans += abs(i - t.find(s[i]))
        return ans