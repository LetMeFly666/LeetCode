'''
Author: LetMeFly
Date: 2023-12-15 16:04:20
LastEditors: LetMeFly
LastEditTime: 2023-12-15 16:07:56
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, left: Optional[TreeNode], right: Optional[TreeNode], shouldReverse: bool) -> None:
        if not left:
            return
        if shouldReverse:
            left.val, right.val = right.val, left.val
        self.dfs(left.left, right.right, not shouldReverse)
        self.dfs(left.right, right.left, not shouldReverse)

    def reverseOddLevels(self, root: TreeNode) -> TreeNode:
        self.dfs(root.left, root.right, True)
        return root
