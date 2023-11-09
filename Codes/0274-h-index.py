'''
Author: LetMeFly
Date: 2023-10-29 07:14:49
LastEditors: LetMeFly
LastEditTime: 2023-10-29 07:21:10
'''
from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(key=lambda x: -x)
        for i in range(len(citations)):
            if i + 1 > citations[i]:
                return i
        return len(citations)
