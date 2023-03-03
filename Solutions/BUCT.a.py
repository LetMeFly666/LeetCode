'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-03-03 17:10:12
'''
from queue import PriorityQueue

class Edge:
    toNode = weight = 0

    def __init__(self, toNode, weight) -> None:
        self.toNode = toNode
        self.weight = weight
    
    def __lt__(self, other: "Edge") -> bool:
        return self.weight < other.weight

T = int(input())
for _CASE in range(T):
    n, m = map(int, input().split())
    visited = [False for _ in range(n + 1)]
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append(Edge(v, w))
        graph[v].append(Edge(u, w))
    visited[1] = True
    pq = PriorityQueue()
    for thisNode in graph[1]:
        pq.put(thisNode)
    ans = 0
    cntEdge = 0
    while cntEdge < n - 1:
        if pq.empty():
            break
        thisEdge = pq.get()
        if not visited[thisEdge.toNode]:
            visited[thisEdge.toNode] = True
            ans += thisEdge.weight
            cntEdge += 1
            for thatEdge in graph[thisEdge.toNode]:
                pq.put(thatEdge)
    if cntEdge is not n - 1:
        print("0")
    else:
        print(ans)
