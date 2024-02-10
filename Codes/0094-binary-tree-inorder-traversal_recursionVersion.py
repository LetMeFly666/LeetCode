'''
Author: LetMeFly
Date: 2024-02-10 11:29:24
LastEditors: LetMeFly
LastEditTime: 2024-02-10 11:30:40
'''
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        st = [(root, False)]
        while st:
            thisNode, ifPushedChild = st.pop()
            if not thisNode:
                continue
            if ifPushedChild:
                ans.append(thisNode.val)
            else:
                st.append((root.right, False))
                st.append((root, True))
                st.append((root.left, False))
        return ans
