'''
Author: LetMeFly
Date: 2024-02-11 10:50:53
LastEditors: LetMeFly
LastEditTime: 2024-02-11 10:52:08
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
        self.ans.append(root.val)
        self.dfs(root.left)
        self.dfs(root.right)
    
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
