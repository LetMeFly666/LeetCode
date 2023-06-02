'''
Author: LetMeFly
Date: 2023-06-02 20:27:23
LastEditors: LetMeFly
LastEditTime: 2023-06-02 20:39:44
'''
from typing import List


def isYuan(c: str) -> bool:
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        prefix = [0] * (len(words) + 1)
        for i in range(len(words)):
            prefix[i + 1] = prefix[i] + (isYuan(words[i][0]) and isYuan(words[i][-1]))
        return [prefix[q[1] + 1] - prefix[q[0]] for q in queries]