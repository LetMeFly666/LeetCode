'''
Author: LetMeFly
Date: 2023-06-23 07:43:17
LastEditors: LetMeFly
LastEditTime: 2023-06-23 07:45:02
'''
from typing import List

class Solution:
    def value(self, s: str) -> int:
        ans = 0
        for c in s:
            if ord(c) < ord('0') or ord(c) > ord('9'):
                return len(s)
            ans = ans * 10 + ord(c) - ord('0')
        return ans

    def maximumValue(self, strs: List[str]) -> int:
        ans = 0
        for str in strs:
            ans = max(ans, self.value(str))
        return ans