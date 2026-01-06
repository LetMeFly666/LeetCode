'''
Author: LetMeFly
Date: 2026-01-06 10:19:17
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-06 10:44:20
'''
from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        ans, maximum = 0, -1000000000
        nowLayer = 0
        q = deque([root])
        while q:
            nowLayer += 1
            layerSum = 0
            newQ = deque([])
            for node in q:
                layerSum += node.val
                if node.left:
                    newQ.append(node.left)
                if node.right:
                    newQ.append(node.right)
            q = newQ
            if layerSum > maximum:
                maximum = layerSum
                ans = nowLayer
        return ans