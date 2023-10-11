'''
Author: LetMeFly
Date: 2023-10-11 09:52:04
LastEditors: LetMeFly
LastEditTime: 2023-10-11 09:54:44
'''
from typing import List

class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        mp = {}
        for s in positive_feedback:
            mp[s] = -3
        for s in negative_feedback:
            mp[s] = 1
        v = []
        for i in range(len(report)):
            v.append([sum(mp.get(word, 0) for word in report[i].split()), student_id[i]])
        v.sort()
        return [t[1] for t in v[:k]]