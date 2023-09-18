'''
Author: LetMeFly
Date: 2023-09-18 08:17:52
LastEditors: LetMeFly
LastEditTime: 2023-09-18 08:31:18
'''
from typing import List, Optional, Tuple

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if not root:
            return 0, 0
        robleft, notleft = self.dfs(root.left)
        robright, notright = self.dfs(root.right)
        robthis = root.val + notleft + notright
        notthis = max(robleft, notleft) + max(robright, notright)
        return robthis, notthis
    
    def rob(self, root: List[TreeNode]) -> int:
        return max(self.dfs(root))