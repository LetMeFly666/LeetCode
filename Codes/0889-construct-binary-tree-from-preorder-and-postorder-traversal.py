'''
Author: LetMeFly
Date: 2024-02-22 10:21:53
LastEditors: LetMeFly
LastEditTime: 2024-02-22 10:29:01
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, preOrder: List[int], preLeft: int, preRight: int, postOrder: List[int], postLeft: int, postRight: int) -> Optional[TreeNode]:
        if preLeft >= preRight:
            return None
        if preLeft + 1 == preRight:
            return TreeNode(preOrder[preLeft])
        leftLength = self.ma[preOrder[preLeft + 1]] - postLeft + 1
        return TreeNode(
            preOrder[preLeft],
            self.dfs(preOrder, preLeft + 1, preLeft + 1 + leftLength, postOrder, postLeft, postLeft + leftLength),
            self.dfs(preOrder, preLeft + 1 + leftLength, preRight, postOrder, postLeft + leftLength, postRight - 1)
        )
    
    def constructFromPrePost(self, preOrder: List[int], postOrder: List[int]) -> TreeNode:
        self.ma = dict()
        for i in range(len(postOrder)):
            self.ma[postOrder[i]] = i
        return self.dfs(preOrder, 0, len(preOrder), postOrder, 0, len(postOrder))
