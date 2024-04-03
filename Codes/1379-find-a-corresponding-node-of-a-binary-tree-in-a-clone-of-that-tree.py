'''
Author: LetMeFly
Date: 2024-04-03 13:02:16
LastEditors: LetMeFly
LastEditTime: 2024-04-03 13:07:48
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        q = [cloned]
        while True:
            thisNode = q.pop()
            if thisNode.val == target.val:
                return thisNode
            if thisNode.left:
                q.append(thisNode.left)
            if thisNode.right:
                q.append(thisNode.right)
