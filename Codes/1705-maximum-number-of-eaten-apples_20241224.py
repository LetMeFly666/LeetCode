'''
Author: LetMeFly
Date: 2024-12-24 18:46:52
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-24 18:56:55
'''
from typing import List
import heapq

class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        pq = []
        ans = 0
        for day in range(len(apples)):
            if apples[day]:
                heapq.heappush(pq, (day + days[day], apples[day]))
            while pq:
                rotDay, appleNum = heapq.heappop(pq)
                if rotDay <= day:
                    continue
                ans += 1
                appleNum -= 1
                if appleNum:
                    heapq.heappush(pq, (rotDay, appleNum))
                break
        day += 1  # 注意这里和C不一样，python执行完day是能取到的右值
        while pq:
            rotDay, appleNum = heapq.heappop(pq)
            eat = max(0, min(rotDay - day, appleNum))
            ans += eat
            day += eat
        return ans