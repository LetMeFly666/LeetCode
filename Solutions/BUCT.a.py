'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-02-24 21:31:19
'''
def Dijkstra(network, s, d):  # 迪杰斯特拉算法，算s-d的最短路径，并返回该路径和代价
    # network：网络拓扑,s：起始节点,d：目的节点
    # print("Start Dijstra Path")
    path = []  # s-d的最短路径
    n = len(network)  # 邻接矩阵维度，即节点个数
    # print("节点个数n{}".format(n))
    fmax = 999
    w = [[0 for i in range(n)] for j in range(n)]  # 邻接矩阵转化成维度矩阵，即0→max
    # print("这个是w{}" .format(w))
    book = [0 for i in range(n)]  # 是否已经是最小的标记列表
    # print("这个是book{}" .format(book))
    dis = [fmax for i in range(n)]  # s到其他节点的最小距离
    dis[s - 1] = 0  # 给起始点到自身的距离重新赋值为0
    # print("这个是dis{}" .format(dis))
    book[s - 1] = 1  # 节点编号从1开始，列表序号从0开始
    midpath = [-1 for i in range(n)]  # 上一跳列表
    # print("这个是midpath{}".format(midpath))
    for i in range(n):
        for j in range(n):
            if network[i][j] != 0:
                w[i][j] = network[i][j]  # 0→max
            else:
                w[i][j] = fmax
            if i == s - 1 and network[i][j] != 0:  # 直连的节点最小距离就是network[i][j]
                dis[j] = network[i][j]
    for i in range(n - 1):  # n-1次遍历，除了s节点
        min = fmax
        for j in range(n):
            if book[j] == 0 and dis[j] < min:  # 如果未遍历且距离最小
                min = dis[j]
                u = j
        book[u] = 1
        for v in range(n):  # u直连的节点遍历一遍
            if dis[v] > dis[u] + w[u][v]:
                dis[v] = dis[u] + w[u][v]
                midpath[v] = u + 1  # 上一跳更新
    j = d - 1  # j是序号
    path.append(d)  # 因为存储的是上一跳,所以先加入目的节点d，最后倒置
    while midpath[j] != -1:
        path.append(midpath[j])
        j = midpath[j] - 1
    path.append(s)
    path.reverse()  # 倒置列表
    # print(path)  # path是路径
    # print(dis)  # dis是到每个位置的最短距离
    for i in range(n):
        print(dis[i], end=" ")


t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    network = [[0 for i in range(n)] for j in range(n)]
    for i in range(m):
        a, b, c = map(int, input().split())
        network[a - 1][b - 1] = c
    start = int(input())
    Dijkstra(network, start, 1)
