'''
Author: LetMeFly
Date: 2023-10-13 13:55:48
LastEditors: LetMeFly
LastEditTime: 2023-10-13 14:13:38
'''
from typing import List
from sortedcontainers import SortedList


class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        whenNotRain = SortedList()
        whichAndRain = {}
        ans = [1] * len(rains)
        for i in range(len(rains)):
            if not rains[i]:
                whenNotRain.add(i)
                continue
            ans[i] = -1
            if rains[i] in whichAndRain:
                lastRainDay = whichAndRain[rains[i]]
                it = whenNotRain.bisect_right(lastRainDay)
                if it == len(whenNotRain):
                    return {}
                ans[whenNotRain[it]] = rains[i]
                whenNotRain.discard(whenNotRain[it])
            whichAndRain[rains[i]] = i
        return ans
