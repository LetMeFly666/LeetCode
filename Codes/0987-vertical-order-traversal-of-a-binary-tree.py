'''
Author: LetMeFly
Date: 2024-02-13 11:27:11
LastEditors: LetMeFly
LastEditTime: 2024-02-13 11:34:26
'''
from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        q = [(0, 0, root)]  # [(col, depth, node), ...
        v = []  # [(col, depth, val), ...]
        while q:
            thisCol, thisDepth, thisNode = q.pop()  # actually is't queue but a stack
            v.append((thisCol, thisDepth, thisNode.val))
            if thisNode.left:
                q.append((thisCol - 1, thisDepth + 1, thisNode.left))
            if thisNode.right:
                q.append((thisCol + 1, thisDepth + 1, thisNode.right))
        v.sort()
        ans = []
        lastCol = 100000
        for col, _, val in v:
            if col != lastCol:
                lastCol = col
                ans.append([])
            ans[-1].append(val)
        return ans
