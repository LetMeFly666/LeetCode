'''
Author: LetMeFly
Date: 2023-09-11 14:17:58
LastEditors: LetMeFly
LastEditTime: 2023-09-11 14:24:35
'''
from typing import List
import heapq

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda a : a[1])
        pq = []
        totalTime = 0
        for duration, lastday in courses:
            if lastday - duration >= totalTime:
                totalTime += duration
                heapq.heappush(pq, -duration)
            elif pq and -pq[0] > duration:
                totalTime = totalTime + duration -(-pq[0])
                heapq.heapreplace(pq, -duration)
        return len(pq)

