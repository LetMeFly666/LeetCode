'''
Author: LetMeFly
Date: 2023-07-31 21:20:43
LastEditors: LetMeFly
LastEditTime: 2023-07-31 21:28:13
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def getMiddle(self, head: ListNode) -> ListNode:  # [0, 1, 2] -> 1, [0, 1] -> 0
        fast = slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        return slow

    def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        next = head.next
        head.next = None
        while next:
            nextNext = next.next
            next.next = head
            head = next
            next = nextNext
        return head

    def merge(self, p1: ListNode, p2: Optional[ListNode]):
        while p1 and p2:
            p1next = p1.next
            p2next = p2.next
            p1.next = p2
            p2.next = p1next
            p1, p2 = p1next, p2next

    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        middle4pre = self.getMiddle(head)
        middle = self.reverse(middle4pre.next)
        middle4pre.next = None
        self.merge(head, middle)