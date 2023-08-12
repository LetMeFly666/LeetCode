'''
Author: LetMeFly
Date: 2023-08-12 08:27:01
LastEditors: LetMeFly
LastEditTime: 2023-08-12 08:37:18
'''
from typing import List, Optional
import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

ListNode.__lt__ = lambda a, b: a.val < b.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []
        for node in lists:
            if node:
                heapq.heappush(pq, node)
        head = ListNode()
        p = head
        while pq:
            thisNode = heapq.heappop(pq)
            p.next = thisNode
            p = thisNode
            if thisNode.next:
                heapq.heappush(pq, thisNode.next)
        return head.next