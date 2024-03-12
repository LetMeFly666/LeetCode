'''
Author: LetMeFly
Date: 2024-03-12 09:25:44
LastEditors: LetMeFly
LastEditTime: 2024-03-12 09:27:47
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    

class FindElements:
    def dfs(self, root: Optional[TreeNode], val: int) -> None:
        if not root:
            return
        root.val = val
        self.se.add(val)
        self.dfs(root.left, val * 2 + 1)
        self.dfs(root.right, val * 2 + 2)

    def __init__(self, root: TreeNode):
        self.se = set()
        self.dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.se


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)