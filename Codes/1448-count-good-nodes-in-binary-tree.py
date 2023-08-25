'''
Author: LetMeFly
Date: 2023-08-25 11:05:42
LastEditors: LetMeFly
LastEditTime: 2023-08-25 11:11:09
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: Optional[TreeNode], parentMax=-100000) -> int:
        if not root:
            return 0
        nowMax = max(root.val, parentMax)
        return (root.val >= parentMax) + self.goodNodes(root.left, nowMax) + self.goodNodes(root.right, nowMax)