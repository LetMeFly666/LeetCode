from typing import Optional

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
        self.dfs(root.right)
        self.last += root.val
        root.val = self.last
        self.dfs(root.left)
    
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.last = 0
        self.dfs(root)
        return root
