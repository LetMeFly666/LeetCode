'''
Author: LetMeFly
Date: 2023-05-30 08:53:29
LastEditors: LetMeFly
LastEditTime: 2023-05-30 09:03:19
'''
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def dfs(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        keepLeft = self.dfs(root.left)
        keepRight = self.dfs(root.right)
        if root.val in self.toDelete:  # 删root
            if keepLeft:
                self.ans.append(root.left)
            if keepRight:
                self.ans.append(root.right)
            return False
        else:
            root.left = root.left if keepLeft else None
            root.right = root.right if keepRight else None
            return True
    
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        self.ans = []
        self.toDelete = set()
        for t in to_delete:
            self.toDelete.add(t)
        if self.dfs(root):
            self.ans.append(root)
        return self.ans