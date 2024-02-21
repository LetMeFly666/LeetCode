'''
Author: LetMeFly
Date: 2024-02-21 10:03:58
LastEditors: LetMeFly
LastEditTime: 2024-02-21 10:09:43
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, inorder: List[int], inLeft: int, inRight: int, postorder: List[int], postLeft: int, postRight: int) -> Optional[TreeNode]:
        if inLeft >= inRight:
            return None
        thisNode = TreeNode(postorder[postRight - 1])
        loc = self.ma[postorder[postRight - 1]]
        thisNode.left = self.dfs(inorder, inLeft, loc, postorder, postLeft, postLeft + (loc - inLeft))
        thisNode.right = self.dfs(inorder, loc + 1, inRight, postorder, postLeft + (loc - inLeft), postRight - 1)
        return thisNode
    
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.ma = dict()
        for i in range(len(inorder)):
            self.ma[inorder[i]] = i
        return self.dfs(inorder, 0, len(inorder), postorder, 0, len(postorder))
