'''
Author: LetMeFly
Date: 2024-02-14 10:10:40
LastEditors: LetMeFly
LastEditTime: 2024-02-14 10:11:53
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        q = []
        if root:
            q.append(root)
        while q:
            ans.append([])
            for _ in range(len(q)):
                thisNode = q[0]
                q = q[1:]
                ans[-1].append(thisNode.val)
                if thisNode.left:
                    q.append(thisNode.left)
                if thisNode.right:
                    q.append(thisNode.right)
        return ans