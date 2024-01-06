'''
Author: LetMeFly
Date: 2024-01-06 11:40:36
LastEditors: LetMeFly
LastEditTime: 2024-01-06 11:43:31
'''
from typing import Optional
from math import gcd

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = head
        while head and head.next:
            mid = ListNode(gcd(head.val, head.next.val))
            mid.next = head.next
            head.next = mid
            head = mid.next
        return ans