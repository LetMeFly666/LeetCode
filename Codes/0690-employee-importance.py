'''
Author: LetMeFly
Date: 2024-08-26 23:44:08
LastEditors: LetMeFly
LastEditTime: 2024-08-26 23:46:27
'''
from typing import List

# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        table = dict()
        for e in employees:
            table[e.id] = e
        ans = 0
        q:List['Employee'] = [table[id]]
        while q:
            this = q.pop()
            ans += this.importance
            for next in this.subordinates:
                q.append(table[next])
        return ans
