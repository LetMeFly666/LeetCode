'''
Author: LetMeFly
Date: 2025-07-14 23:37:54
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-14 23:43:59
'''
from typing import Optional

# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        ans = 0
        while head:
            ans = ans * 2 + head.val
            head = head.next
        return ans