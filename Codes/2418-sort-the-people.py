'''
Author: LetMeFly
Date: 2023-04-25 20:37:27
LastEditors: LetMeFly
LastEditTime: 2023-04-25 20:40:51
'''
from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        a = [[-heights[i], names[i]] for i in range(len(names))]
        a.sort()
        return [i[1] for i in a]