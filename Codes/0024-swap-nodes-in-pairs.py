'''
Author: LetMeFly
Date: 2023-08-06 09:58:57
LastEditors: LetMeFly
LastEditTime: 2023-08-06 10:07:15
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, p: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0, p)
        p = head
        while p.next and p.next.next:
            first, second, third = p.next, p.next.next, p.next.next.next
            p.next, first.next, second.next = second, third, first
            p = first
        return head.next