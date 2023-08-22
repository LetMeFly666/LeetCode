'''
Author: LetMeFly
Date: 2023-08-22 08:57:52
LastEditors: LetMeFly
LastEditTime: 2023-08-22 09:05:15
'''
from typing import List

class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        ans = 1
        lastSeat = -1
        for i in range(len(seats)):
            if seats[i]:
                if lastSeat == -1:
                    ans = max(ans, i)
                else:
                    ans = max(ans, (i - lastSeat) // 2)
                lastSeat = i
        ans = max(ans, len(seats) - lastSeat - 1)
        return ans