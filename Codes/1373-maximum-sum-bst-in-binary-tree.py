'''
Author: LetMeFly
Date: 2023-05-20 09:51:53
LastEditors: LetMeFly
LastEditTime: 2023-05-20 10:44:54
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class MyNode:
    def __init__(self, minValue: int, maxValue: int, sumValue: int, isBST: bool):
        self.minValue = minValue
        self.maxValue = maxValue
        self.sumValue = sumValue
        self.isBST = isBST


class Solution:
    def dfs(self, root: Optional[TreeNode]) -> MyNode:
        if not root:
            return MyNode(1e9, -1e9, 0, True)
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        if left.isBST and right.isBST and left.maxValue < root.val and right.minValue > root.val:
            toReturn = MyNode(min(left.minValue, root.val), max(right.maxValue, root.val), left.sumValue + right.sumValue + root.val, True)
            self.ans = max(self.ans, toReturn.sumValue)
            return toReturn
        else:
            return MyNode(0, 0, 0, False)

    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        self.dfs(root)
        return self.ans