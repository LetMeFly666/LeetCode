'''
Author: LetMeFly
Date: 2023-09-10 14:08:43
LastEditors: LetMeFly
LastEditTime: 2023-09-10 14:11:30
'''
from collections import deque
from typing import List

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for a, b in prerequisites:
            graph[b].append(a)
            indegree[a] += 1
        q = deque()
        for i in range(numCourses):
            if not indegree[i]:
                q.append(i)
        ans = []
        while q:
            thisCourse = q.popleft()
            ans.append(thisCourse)
            for to in graph[thisCourse]:
                indegree[to] -= 1
                if not indegree[to]:
                    q.append(to)
        return ans if len(ans) == numCourses else []