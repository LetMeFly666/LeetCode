'''
Author: LetMeFly
Date: 2023-08-20 09:07:52
LastEditors: LetMeFly
LastEditTime: 2023-08-20 09:09:36
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def checkTree(self, root: TreeNode) -> bool:
        return root.val == root.left.val + root.right.val