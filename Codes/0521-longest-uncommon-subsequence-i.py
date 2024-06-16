'''
Author: LetMeFly
Date: 2024-06-16 18:16:34
LastEditors: LetMeFly
LastEditTime: 2024-06-16 18:16:37
'''
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return max(len(a), len(b)) if a != b else -1