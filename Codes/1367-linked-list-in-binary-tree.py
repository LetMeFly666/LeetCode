'''
Author: LetMeFly
Date: 2024-12-30 15:00:35
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-30 15:13:58
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, l: Optional[ListNode], r: Optional[TreeNode]) -> bool:
        if not l:
            return True
        if not r:
            return False
        if l.val == r.val:
            if self.dfs(l.next, r.left) or self.dfs(l.next, r.right):
                return True
        if l == self.head:
            if self.dfs(l, r.left) or self.dfs(l, r.right):
                return True
        return False

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        self.head = head
        return self.dfs(head, root)