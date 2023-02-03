'''
Author: LetMeFly
Date: 2023-02-03 22:57:24
LastEditors: LetMeFly
LastEditTime: 2023-02-03 23:04:33
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    

class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        nodeX = TreeNode()
        def dfs(root: TreeNode) -> int:
            if not root:
                return 0
            if root.val == x:
                nonlocal nodeX
                nodeX = root
            return dfs(root.left) + dfs(root.right) + 1
        dfs(root)
        left = dfs(nodeX.left)
        right = dfs(nodeX.right)
        return (left > n - left) or (right > n - right) or (n - left - right - 1 > left + right + 1)
