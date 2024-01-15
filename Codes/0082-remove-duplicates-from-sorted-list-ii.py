'''
Author: LetMeFly
Date: 2024-01-15 21:45:39
LastEditors: LetMeFly
LastEditTime: 2024-01-15 21:53:04
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode(1000, head)
        lastNode, thisNode = ans, head
        while thisNode and thisNode.next:
            if thisNode.val == thisNode.next.val:
                nextNode = thisNode.next.next
                while nextNode and thisNode.val == nextNode.val:
                    nextNode = nextNode.next
                lastNode.next = nextNode
                thisNode = nextNode
            else:
                lastNode, thisNode = thisNode, thisNode.next
        return ans.next