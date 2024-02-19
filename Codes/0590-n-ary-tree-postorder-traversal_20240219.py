'''
Author: LetMeFly
Date: 2024-02-19 12:30:21
LastEditors: LetMeFly
LastEditTime: 2024-02-19 12:31:29
'''
from typing import List, Optional

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def dfs(self, root: 'Node') -> None:
        for nextNode in root.children:
            self.dfs(nextNode)
        self.ans.append(root.val)
    
    def postorder(self, root: Optional['Node']) -> List[int]:
        self.ans = []
        if root:
            self.dfs(root)
        return self.ans
