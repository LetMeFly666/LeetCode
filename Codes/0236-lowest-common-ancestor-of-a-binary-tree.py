'''
Author: LetMeFly
Date: 2024-02-09 12:19:22
LastEditors: LetMeFly
LastEditTime: 2024-02-09 12:24:33
'''
# AC,93.83%,86.17%
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Status:
    none = 0
    onlyP = 1
    onlyQ = 2
    both = 3

class Solution:
    def dfs(self, root: Optional[TreeNode], p: 'TreeNode', q: 'TreeNode') -> Status:
        if not root:
            return Status.none
        thisStatus = Status.none
        if root == p:
            thisStatus |= Status.onlyP
        if root == q:
            thisStatus |= Status.onlyQ
        thisStatus |= self.dfs(root.left, p, q) | self.dfs(root.right, p, q)
        if thisStatus == Status.both and not self.ans:
            self.ans = root
        return thisStatus
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ans = None
        self.dfs(root, p, q)
        return self.ans
