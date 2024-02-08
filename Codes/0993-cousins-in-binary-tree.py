'''
Author: LetMeFly
Date: 2024-02-08 12:08:59
LastEditors: LetMeFly
LastEditTime: 2024-02-08 12:12:33
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode], depth: int, father: Optional[TreeNode]) -> None:
        if not root:
            return
        if root.val == self.x:
            self.x_father = father
            self.x_depth = depth
        if root.val == self.y:
            self.y_father = father
            self.y_depth = depth
        self.dfs(root.left, depth + 1, root)
        self.dfs(root.right, depth + 1, root)
    
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        self.x = x
        self.y = y
        self.dfs(root, 0, None)
        return self.x_father != self.y_father and self.x_depth == self.y_depth
