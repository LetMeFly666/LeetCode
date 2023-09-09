'''
Author: LetMeFly
Date: 2023-09-09 10:11:22
LastEditors: LetMeFly
LastEditTime: 2023-09-09 10:26:39
'''
from collections import deque
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for a, b in prerequisites:
            graph[b].append(a)
            indegree[a] += 1
        q = deque()
        for i in range(numCourses):
            if not indegree[i]:
                q.append(i)
        remain = numCourses
        while q:
            thisCourse = q.popleft()
            remain -= 1
            for to in graph[thisCourse]:
                indegree[to] -= 1
                if not indegree[to]:
                    q.append(to)
        return not remain


if __name__ == "__main__":
    print(Solution().canFinish(2, [[1, 0]]))