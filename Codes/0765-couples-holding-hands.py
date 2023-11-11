'''
Author: LetMeFly
Date: 2023-11-11 22:42:21
LastEditors: LetMeFly
LastEditTime: 2023-11-11 22:48:32
'''
from typing import List

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        graph = [[] for _ in range(len(row) // 2)]
        for i in range(0, len(row), 2):
            graph[row[i] // 2].append(row[i + 1] // 2)
            graph[row[i + 1] // 2].append(row[i] // 2)
        visited = [False] * (len(row) // 2)
        ans = 0
        for i in range(len(row) // 2):
            if visited[i]:
                continue
            q = []
            q.append(i)
            thisCnt = 0
            while q:
                thisCnt += 1
                thisPeople = q.pop()
                for nextPeople in graph[thisPeople]:
                    if not visited[nextPeople]:
                        visited[nextPeople] = True
                        q.append(nextPeople)
            ans += thisCnt - 1
        return ans