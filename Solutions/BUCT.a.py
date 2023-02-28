'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-02-28 12:56:16
'''
T = int(input())
for __CASE in range(T):
    n, m = map(int, input().split())
    # init
    visited = [False for _ in range(n + 1)]
    graph = [[] for _ in range(n + 1)]
    shortestDistance = [1e9 for _ in range(n + 1)]
    # cin
    for _ in range(m):
        u, v, d = map(int, input().split())
        graph[u].append((v, d))
    start = int(input())
    # begin
    shortestDistance[start] = 0
    for _ in range(n):
        thisMinDistance = 1e9
        shortestPoint = -1
        for j in range(1, n + 1):
            if not visited[j] and shortestDistance[j] < thisMinDistance:
                thisMinDistance = shortestDistance[j]
                shortestPoint = j
        if shortestPoint == -1:
            break
        visited[shortestPoint] = True
        for toPoint, thisDistance in graph[shortestPoint]:
            shortestDistance[toPoint] = min(shortestDistance[toPoint], shortestDistance[shortestPoint] + thisDistance)
    # cout
    for i in range(1, n + 1):
        if shortestDistance[i] == 1e9:
            print("impossible", end=' ')
        else:
            print(shortestDistance[i], end=' ')
    print()
