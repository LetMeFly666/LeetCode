'''
Author: LetMeFly
Date: 2024-02-07 10:17:50
LastEditors: LetMeFly
LastEditTime: 2024-02-07 10:20:13
'''
from collections import defaultdict

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def replaceValueInTree(self, root: TreeNode) -> TreeNode:
        v = [(root, None)]
        while v:
            valSum = 0
            originalVal = defaultdict(int)
            nextV = []
            for thisNode, broNode in v:
                valSum += thisNode.val
                originalVal[thisNode] = thisNode.val
                if thisNode.left:
                    nextV.append((thisNode.left, thisNode.right))
                if thisNode.right:
                    nextV.append((thisNode.right, thisNode.left))
            for thisNode, broNode in v:
                thisNode.val = valSum - thisNode.val - originalVal[broNode]
            v = nextV
        return root