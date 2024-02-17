'''
Author: LetMeFly
Date: 2024-02-17 10:52:19
LastEditors: LetMeFly
LastEditTime: 2024-02-17 10:54:27
'''
from typing import List, Optional

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def levelOrder(self, root: Optional[Node]) -> List[List[int]]:
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
                for nextNode in thisNode.children:
                    q.append(nextNode)
        return ans
