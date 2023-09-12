'''
Author: LetMeFly
Date: 2023-09-12 10:02:01
LastEditors: LetMeFly
LastEditTime: 2023-09-12 10:05:49
'''
from typing import List


class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        for a, b in prerequisites:
            graph[a].append(b)
            indegree[b] += 1
        
        q = []
        for i in range(numCourses):
            if not indegree[i]:
                q.append(i)
        
        isPre = [[False for _ in range(numCourses)] for __ in range(numCourses)]
        while q:
            thisCourse = q.pop()
            for nextCourse in graph[thisCourse]:
                indegree[nextCourse] -= 1
                if not indegree[nextCourse]:
                    q.append(nextCourse)
                isPre[thisCourse][nextCourse] = True
                for i in range(numCourses):
                    isPre[i][nextCourse] |= isPre[i][thisCourse]
        
        ans = []
        for a, b in queries:
            ans.append(isPre[a][b])
        return ans
