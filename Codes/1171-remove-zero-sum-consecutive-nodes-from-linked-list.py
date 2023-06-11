'''
Author: LetMeFly
Date: 2023-06-11 14:32:17
LastEditors: LetMeFly
LastEditTime: 2023-06-11 14:53:51
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        emptyHead = ListNode(0, head)
        lastAppear = dict()
        cnt = 0
        node = emptyHead
        while node:
            cnt += node.val
            lastAppear[cnt] = node
            node = node.next
        cnt = 0
        node = emptyHead
        while node:
            cnt += node.val
            node.next = lastAppear[cnt].next
            node = node.next
        return emptyHead.next
