'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-03-02 21:40:40
'''

# My

class Node:
    c = ''
    isLeaf = False
    leftChild, rightChild = '', ''
    weight = 0

ans = dict()

def output(root: Node, nowString: str):
    if root.isLeaf:
        ans[root.c] = nowString
        return
    if root.leftChild:
        output(root.leftChild, nowString + '0')
    if root.rightChild:
        output(root.rightChild, nowString + '1')

T = int(input())
for _CASE in range(T):
    n = int(input())
    charOrder = []
    ans.clear()
    Nodes = []
    # input
    for _ in range(n):
        c, weight = input().split()
        weight = float(weight)
        charOrder.append(c)
        thisNode = Node()
        thisNode.c = c
        thisNode.weight = weight
        thisNode.isLeaf = True
        Nodes.append(thisNode)
    # build
    while len(Nodes) > 1:
        Nodes.sort(key=lambda x : x.weight)
        leftNode, rightNode = Nodes[0], Nodes[1]
        Nodes = Nodes[2:]
        newNode = Node()
        newNode.isLeaf = False
        newNode.weight = leftNode.weight + rightNode.weight
        newNode.leftChild = leftNode
        newNode.rightChild = rightNode
        Nodes.append(newNode)
    root = ''
    if Nodes[0].isLeaf:
        root = Node()
        root.isLeaf = False
        root.leftChild = Nodes[0]
        root.rightChild = ''
        root.weight = Nodes[0].weight
    else:
        root = Nodes[0]
    # output
    output(root, '')
    for c in charOrder:
        print(f"{c}: {ans[c]} ", end='')
    print()
