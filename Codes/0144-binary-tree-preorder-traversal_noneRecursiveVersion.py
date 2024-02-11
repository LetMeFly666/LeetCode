'''
Author: LetMeFly
Date: 2024-02-11 10:57:28
LastEditors: LetMeFly
LastEditTime: 2024-02-11 10:58:28
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        st = [root]
        while st:
            thisNode = st.pop()
            if not thisNode:
                continue
            ans.append(thisNode.val)
            st.append(thisNode.right)
            st.append(thisNode.left)
        return ans