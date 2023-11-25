'''
Author: LetMeFly
Date: 2023-11-25 17:38:16
LastEditors: LetMeFly
LastEditTime: 2023-11-25 17:42:49
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: TreeNode, mask: int) -> None:
        mask ^= (1 << root.val)
        if not root.left and not root.right:
            self.ans += mask == (mask & -mask)
        if root.left:
            self.dfs(root.left, mask)
        if root.right:
            self.dfs(root.right, mask)
    
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        self.ans = 0
        self.dfs(root, 0)
        return self.ans