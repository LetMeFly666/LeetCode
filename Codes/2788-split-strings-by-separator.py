'''
Author: LetMeFly
Date: 2024-01-20 23:24:06
LastEditors: LetMeFly
LastEditTime: 2024-01-20 23:25:26
'''
from typing import List

class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for word in words:
            splited = word.split(separator)
            for this in splited:
                if this:
                    ans.append(this)
        return ans