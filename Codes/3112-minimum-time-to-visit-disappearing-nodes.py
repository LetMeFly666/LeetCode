'''
Author: LetMeFly
Date: 2024-07-18 10:40:34
LastEditors: LetMeFly
LastEditTime: 2024-07-18 11:03:12
'''
from typing import List
import heapq

class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        graph = [[] for _ in range(n)]
        for x, y, d in edges:
            graph[x].append((y, d))
            graph[y].append((x, d))
        ans = [-1] * n
        pq = [(0, 0)]
        while pq:
            thisTime, thisNode = heapq.heappop(pq)
            if ans[thisNode] != -1:
                continue
            ans[thisNode] = thisTime
            for nextNode, length in graph[thisNode]:
                # print(nextNode, length, ans[nextNode], thisTime + length, disappear[nextNode])  #------------------
                # print(ans[nextNode] != -1)
                # print(thisTime + length < disappear[nextNode])
                if ans[nextNode] == -1 and thisTime + length < disappear[nextNode]:
                    heapq.heappush(pq, (thisTime + length, nextNode))
        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.minimumTime(3, [[0, 1, 2], [1, 2, 1], [0, 2, 4]], [1, 1, 5]))