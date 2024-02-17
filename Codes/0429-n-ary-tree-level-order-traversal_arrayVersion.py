'''
Author: LetMeFly
Date: 2024-02-17 10:56:01
LastEditors: LetMeFly
LastEditTime: 2024-02-17 10:58:49
'''
from typing import Optional, List

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def levelOrder(self, root: Optional[Node]) -> List[List[int]]:
        ans = []
        a = []
        if root:
            a.append(root)
        while a:
            ans.append([thisNode.val for thisNode in a])
            a = [nextChild for thisNode in a for nextChild in thisNode.children]
        return ans
