'''
Author: LetMeFly
Date: 2023-07-02 07:12:39
LastEditors: LetMeFly
LastEditTime: 2023-07-02 07:15:02
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        p = head
        carry = 0
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            p.next = ListNode(carry % 10)
            p = p.next
            carry //= 10
        return head.next