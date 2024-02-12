'''
Author: LetMeFly
Date: 2024-02-12 10:01:34
LastEditors: LetMeFly
LastEditTime: 2024-02-12 10:03:03
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        st =  [(root, False)]
        while st:
            thisNode, ifPushed = st.pop()
            if not thisNode:
                continue
            if ifPushed:
                ans.append(thisNode.val)
            else:
                st.append((thisNode, True))
                st.append((thisNode.right, False))
                st.append((thisNode.left, False))
        return ans
