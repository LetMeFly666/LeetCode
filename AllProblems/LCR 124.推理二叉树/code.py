# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deduceTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        