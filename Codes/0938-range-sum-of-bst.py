'''
Author: LetMeFly
Date: 2024-02-26 18:59:30
LastEditors: LetMeFly
LastEditTime: 2024-02-26 19:01:00
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode], l: int, r: int) -> None:
        if not root:
            return
        self.dfs(root.left, l, r)
        if l <= root.val <= r:
            self.ans += root.val
        self.dfs(root.right, l, r)

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.ans = 0
        self.dfs(root, low, high)
        return self.ans
