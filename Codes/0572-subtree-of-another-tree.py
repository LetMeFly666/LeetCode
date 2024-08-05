'''
Author: LetMeFly
Date: 2024-08-04 10:43:45
LastEditors: LetMeFly
LastEditTime: 2024-08-04 10:47:59
'''
from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSame(self, a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
        if not a or not b:
            return a == b
        return a.val == b.val and self.isSame(a.left, b.left) and self.isSame(a.right, b.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
        if self.isSame(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)