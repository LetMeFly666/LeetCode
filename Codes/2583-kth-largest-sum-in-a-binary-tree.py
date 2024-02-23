'''
Author: LetMeFly
Date: 2024-02-23 10:26:30
LastEditors: LetMeFly
LastEditTime: 2024-02-23 11:32:41
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthLargestLevelSum(self, root: TreeNode, k: int) -> int:
        values = []
        q = [root]
        while q:
            cnt = 0
            thisLayer = q
            q = []
            for thisNode in thisLayer:
                cnt += thisNode.val
                if thisNode.left:
                    q.append(thisNode.left)
                if thisNode.right:
                    q.append(thisNode.right)
            values.append(cnt)
        values.sort()
        return values[len(values) - k] if len(values) >= k else -1
