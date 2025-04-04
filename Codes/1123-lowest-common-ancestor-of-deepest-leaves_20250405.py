'''
Author: LetMeFly
Date: 2025-04-05 00:49:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-05 00:58:30
'''
from typing import Tuple, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> Tuple[Optional[TreeNode], int]:
        if not root:
            return (root, 0)
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        if left[1] > right[1]:
            return (left[0], left[1] + 1)
        elif left[1] < right[1]:
            return (right[0], right[1] + 1)
        return (root, left[1] + 1)
        
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root)[0]