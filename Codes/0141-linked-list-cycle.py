'''
Author: LetMeFly
Date: 2023-07-29 08:10:28
LastEditors: LetMeFly
LastEditTime: 2023-07-29 08:11:54
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False