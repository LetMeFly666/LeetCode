'''
Author: LetMeFly
Date: 2024-02-12 09:59:42
LastEditors: LetMeFly
LastEditTime: 2024-02-12 10:00:54
'''
from typing import List, Optional

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
        self.dfs(root.right)
        self.ans.append(root.val)
    
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
