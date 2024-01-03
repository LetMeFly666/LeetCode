'''
Author: LetMeFly
Date: 2024-01-03 10:26:57
LastEditors: LetMeFly
LastEditTime: 2024-01-03 10:30:27
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNodes(self, head: ListNode) -> ListNode:
        st = []
        while head:
            while len(st) and st[-1].val < head.val:
                st.pop()
            st.append(head)
            head = head.next
        for i in range(len(st) - 1):
            st[i].next = st[i + 1]
        return st[0]