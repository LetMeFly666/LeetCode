'''
Author: LetMeFly
Date: 2023-05-01 21:00:30
LastEditors: LetMeFly
LastEditTime: 2023-05-01 21:07:40
'''
from typing import List

class Solution:
    def getTime(self, node: int, manager: List[int], informTime: List[int]) -> int:
        if node in self.ma:
            return self.ma[node]
        self.ma[node] = self.getTime(manager[node], manager, informTime) + informTime[manager[node]]
        return self.ma[node]
    
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        ans = 0
        self.ma = dict()
        self.ma[headID] = 0
        for i in range(n):
            ans = max(ans, self.getTime(i, manager, informTime))
        return ans
