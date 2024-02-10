'''
Author: LetMeFly
Date: 2024-02-10 11:14:13
LastEditors: LetMeFly
LastEditTime: 2024-02-10 11:15:16
'''
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root.left)
        self.ans.append(root.val)
        self.dfs(root.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
