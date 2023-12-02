'''
Author: LetMeFly
Date: 2023-12-02 14:14:08
LastEditors: LetMeFly
LastEditTime: 2023-12-02 14:21:01
'''
from typing import List
import heapq

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda x: x[1])
        nowPeopleCnt = 0
        nowPeople = []
        for num, from_, to in trips:
            while nowPeople and nowPeople[0][0] <= from_:
                nowPeopleCnt -= nowPeople[0][1]
                heapq.heappop(nowPeople)
            nowPeopleCnt += num
            if nowPeopleCnt > capacity:
                return False
            heapq.heappush(nowPeople, (to, num))
        return True