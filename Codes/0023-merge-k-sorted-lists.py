'''
Author: LetMeFly
Date: 2023-08-12 08:27:01
LastEditors: LetMeFly
LastEditTime: 2023-08-12 08:30:49
'''
from typing import List, Optional
import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []
        for node in lists:
            if node:
                heapq.heappush(pq, (-node.val, node))
        head = ListNode()
        p = head
        while pq:
            _, thisNode = heapq.heappop(pq)
            p.next = thisNode
            p = thisNode
            if thisNode.next:
                heapq.heappush(pq, (-thisNode.next.val, thisNode.next))
        return head.next