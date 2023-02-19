'''
Author: LetMeFly
Date: 2023-02-19 21:32:05
LastEditors: LetMeFly
LastEditTime: 2023-02-19 21:42:33
'''
from typing import List
from heapq import heapify, heapreplace


class Entry:
    __slots__ = "a", "b"

    def __init__(self, a: int, b: int):
        self.a = a
        self.b = b
    
    def __lt__(self, b: "Entry") -> bool:
        return getScore(self) > getScore(b)


def getScore(a: "Entry") -> float:
    return (a.a + 1) / (a.b + 1) - a.a / a.b


class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        pq = [Entry(*c) for c in classes]
        heapify(pq)
        for _ in range(extraStudents):
            heapreplace(pq, Entry(pq[0].a + 1, pq[0].b + 1))
        return sum(c.a / c.b for c in pq) / len(pq)
