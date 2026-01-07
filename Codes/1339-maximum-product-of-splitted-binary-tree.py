'''
Author: LetMeFly
Date: 2026-01-07 21:29:44
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-07 21:55:18
'''
from typing import Optional  # 昨天改的newSolutions.py(好像是)今天就用上了

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: TreeNode) -> int:
        left, right = 0, 0
        if root.left:
            left = self.dfs(root.left)
            self.sum.append(left)
        if root.right:
            right = self.dfs(root.right)
            self.sum.append(right)
        return root.val + left + right
    
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.sum = []
        sum = self.dfs(root)
        return max(t * (sum - t) for t in self.sum) % 1000000007