'''
Author: LetMeFly
Date: 2025-03-05 22:11:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-05 22:14:01
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 1
        q = [(root, 0)]
        while q:
            nextQ = []
            ans = max(ans, q[-1][1] - q[0][1] + 1)
            for node, num in q:
                if node.left:
                    nextQ.append((node.left, num * 2 + 1))
                if node.right:
                    nextQ.append((node.right, num * 2 + 2))
            q = nextQ
        return ans