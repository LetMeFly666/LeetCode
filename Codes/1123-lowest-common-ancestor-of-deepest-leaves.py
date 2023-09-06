'''
Author: LetMeFly
Date: 2023-09-06 22:50:41
LastEditors: LetMeFly
LastEditTime: 2023-09-06 22:54:59
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]):
        if not root:
            return [None, 0]
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        if left[1] == right[1]:
            return [root, left[1] + 1]
        elif left[1] < right[1]:
            return [right[0], right[1] + 1]
        else:
            return [left[0], left[1] + 1]
    
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root)[0]
