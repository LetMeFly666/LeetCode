'''
Author: LetMeFly
Date: 2025-05-15 10:32:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-15 13:21:42
'''
from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        ans = []
        for i, g in enumerate(groups):
            if not i or g != groups[i - 1]:
                ans.append(words[i])
        return ans