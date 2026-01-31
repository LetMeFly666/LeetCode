'''
Author: LetMeFly
Date: 2026-01-31 13:49:56
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-31 13:56:59
'''
from typing import List
from bisect import bisect_right

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        idx = bisect_right(letters, target)
        return letters[0] if idx == len(letters) else letters[idx]