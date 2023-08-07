'''
Author: LetMeFly
Date: 2023-08-07 07:57:36
LastEditors: LetMeFly
LastEditTime: 2023-08-07 07:58:37
'''
from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s) // 2):
            s[i], s[len(s) - i - 1] = s[len(s) - i - 1], s[i]