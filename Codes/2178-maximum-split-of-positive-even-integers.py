'''
Author: LetMeFly
Date: 2023-07-06 07:45:05
LastEditors: LetMeFly
LastEditTime: 2023-07-06 07:46:14
'''
from typing import List

class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum % 2:
            return []
        ans = []
        now = 2
        while finalSum - now > now:
            ans.append(now)
            finalSum -= now
            now += 2
        ans.append(finalSum)
        return ans