'''
Author: LetMeFly
Date: 2024-04-05 12:02:59
LastEditors: LetMeFly
LastEditTime: 2024-04-05 12:05:13
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode], m: int, M: int) -> None:
        if not root:
            return
        self.ans = max(self.ans, abs(root.val - m), abs(root.val - M))
        m = min(m, root.val)
        M = max(M, root.val)
        self.dfs(root.left, m, M)
        self.dfs(root.right, m, M)
    
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.ans = 0
        self.dfs(root, root.val, root.val)
        return self.ans
