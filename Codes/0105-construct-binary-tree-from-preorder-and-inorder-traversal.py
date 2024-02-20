'''
Author: LetMeFly
Date: 2024-02-20 11:13:14
LastEditors: LetMeFly
LastEditTime: 2024-02-20 11:20:15
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:  # AC,98.61%,91.88%
    def dfs(self, preLeft: int, preRight: int, inLeft: int, inRight: int) -> Optional[TreeNode]:
        if preRight <= preLeft:
            return None
        thisNode = TreeNode(self.preorder[preLeft])
        loc = self.ma[self.preorder[preLeft]]
        leftLength = loc - inLeft
        thisNode.left = self.dfs(preLeft + 1, preLeft + leftLength + 1, inLeft, loc - 1)
        thisNode.right = self.dfs(preLeft + leftLength + 1, preRight, loc + 1, inRight)
        return thisNode
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.preorder = preorder
        self.inorder = inorder
        self.ma = dict()
        for i in range(len(inorder)):
            self.ma[inorder[i]] = i
        return self.dfs(0, len(preorder), 0, len(inorder))
