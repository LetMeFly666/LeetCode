'''
Author: LetMeFly
Date: 2023-04-18 12:01:11
LastEditors: LetMeFly
LastEditTime: 2023-04-18 12:08:00
'''
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        self.ans = 0
    
    def dfs(self, root: Optional[TreeNode], M: int, m: int) -> None:
        if not root:
            return
        self.ans = max(self.ans, abs(root.val - M), abs(root.val - m))
        M = max(M, root.val)
        m = min(m, root.val)
        self.dfs(root.left, M, m)
        self.dfs(root.right, M, m)

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, root.val, root.val)
        return self.ans
