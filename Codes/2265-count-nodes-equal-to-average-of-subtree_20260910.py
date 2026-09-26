'''
Author: LetMeFly
Date: 2026-09-10 14:38:19
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-10 14:53:13
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: TreeNode) -> tuple[int, int]:
        if not root:
            return 0, 0
        vl, nl = self.dfs(root.left)
        vr, nr = self.dfs(root.right)
        v = root.val + vl + vr
        n = 1 + nl + nr
        self.ans += v // n == root.val
        return v, n

    def averageOfSubtree(self, root: TreeNode) -> int:
        self.ans = 0
        self.dfs(root)
        return self.ans
