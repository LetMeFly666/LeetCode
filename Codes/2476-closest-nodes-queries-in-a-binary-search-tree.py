'''
Author: LetMeFly
Date: 2024-02-24 11:04:55
LastEditors: LetMeFly
LastEditTime: 2024-02-24 11:09:41
'''
from typing import List, Optional
from bisect import bisect_left

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root.left)
        self.v.append(root.val)
        self.dfs(root.right)
    
    def closestNodes(self, root: TreeNode, queries: List[int]) -> List[List[int]]:
        self.v = []
        self.dfs(root)
        ans = []
        for q in queries:
            m, M = -1, -1
            loc = bisect_left(self.v, q)
            if loc != len(self.v):
                M = self.v[loc]  # v1中这里笔误写成M=loc了
                if M == q:
                    ans.append([q, q])
                    continue
            if loc:
                m = self.v[loc - 1]
            ans.append([m, M])
        return ans
