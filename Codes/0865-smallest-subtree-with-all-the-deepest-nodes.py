'''
Author: LetMeFly
Date: 2026-01-09 20:55:06
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-09 20:58:21
'''
from typing import Optional, Tuple

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

empty_result = (None, 0)

class Solution:
    def dfs(self, root: TreeNode) -> Tuple[Optional[TreeNode], int]:
        left = self.dfs(root.left) if root.left else empty_result
        right = self.dfs(root.right) if root.right else empty_result
        return [root if left[1] == right[1] else left[0] if left[1] > right[1] else right[0], max(left[1], right[1]) + 1]

    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        return self.dfs(root)[0]