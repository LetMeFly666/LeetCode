'''
Author: LetMeFly
Date: 2025-10-29 19:30:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-29 20:04:49
'''
"""
6 10
20 10 -1
10 21 -1
21 -1 11
11 -1 22
22 12 -1
12 -1 -1
"""
from collections import defaultdict

class Node:
    def __init__(self, val: int):
        self.val = val
        self.left = None
        self.right = None
        self.isRoot = True

ma = defaultdict(Node)

def getNode(val: int) -> Node:
    if val == -1:
        return None
    if val in ma:
        return ma[val]
    ans = Node(val)
    ma[val] = ans
    return ans

# 其实这里返回Node也可以
def getRoot() -> int:
    for val, node in ma.items():
        # print(val, node)
        if node.isRoot:
            return val

n, k = map(int, input().split())

for _ in range(n):
    root, l, r = map(getNode, map(int, input().split()))
    # print(root.val, l.val, r.val)
    root.left = l
    root.right = r
    if l:
        l.isRoot = False
    if r:
        r.isRoot = False

root = getRoot()
# print(root)

ans = 0

"""
status:
0     无状态
1     刚递增过
2     刚递减过
"""
def dfs(root: Node, cnt: int, parent: Node, status: int):
    global ans
    ans = max(ans, cnt)
    if not root:
        return
    
    nextStatus = 0
    if status == 1 and parent.val - root.val >= k:
        cnt += 1
        nextStatus = 2
    if status == 2 and root.val - parent.val >= k:
        cnt += 1
        nextStatus = 1
    if not nextStatus:
        cnt = 1
        if parent and parent.val - root.val >= k:
            cnt += 1
            nextStatus = 2
        if parent and root.val - parent.val >= k:
            cnt += 1
            nextStatus = 1
    dfs(root.left, cnt, root, nextStatus)
    dfs(root.right, cnt, root, nextStatus)


dfs(ma[root], 0, None, 0)

print(ans)
