'''
Author: LetMeFly
Date: 2022-10-13 10:02:28
LastEditors: LetMeFly
LastEditTime: 2022-10-13 10:24:12
'''
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(substr, k) for substr in s.split(c))
        return len(s)
