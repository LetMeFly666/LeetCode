'''
Author: LetMeFly
Date: 2023-09-08 09:25:29
LastEditors: LetMeFly
LastEditTime: 2023-09-08 09:25:31
'''
class Solution:
    def findDelayedArrivalTime(self, arrivalTime: int, delayedTime: int) -> int:
        return (arrivalTime + delayedTime) % 24