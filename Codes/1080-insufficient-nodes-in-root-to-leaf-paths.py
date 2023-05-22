'''
Author: LetMeFly
Date: 2023-05-22 09:32:15
LastEditors: LetMeFly
LastEditTime: 2023-05-22 09:50:24
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        limit -= root.val
        if not root.left and not root.right:
            if limit <= 0:
                return root
            else:
                return None
        left = self.sufficientSubset(root.left, limit) if root.left else None
        right = self.sufficientSubset(root.right, limit) if root.right else None
        if not left and not right:
            return None
        else:
            root.left = left
            root.right = right
            return root