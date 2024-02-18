'''
Author: LetMeFly
Date: 2024-02-18 11:58:17
LastEditors: LetMeFly
LastEditTime: 2024-02-18 11:59:48
'''
from typing import Optional, List

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def dfs(self, root: Optional['Node']) -> None:
        if not root:
            return
        self.ans.append(root.val)
        for nextChild in root.children:
            self.dfs(nextChild)
    
    def preorder(self, root: Optional['Node']) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
