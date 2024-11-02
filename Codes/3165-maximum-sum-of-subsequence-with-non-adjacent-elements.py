'''
Author: LetMeFly
Date: 2024-11-02 12:22:22
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-02 12:36:02
'''
from typing import List

MOD = 1_000_000_007
class Solution:
    def maintain(self, index: int) -> None:
        leftNode = self.tree[2 * index + 1]
        rightNode = self.tree[2 * index + 2]
        self.tree[index] = [
            max(leftNode[0] + rightNode[2], leftNode[1] + rightNode[0]),
            max(leftNode[0] + rightNode[3], leftNode[1] + rightNode[1]),
            max(leftNode[2] + rightNode[2], leftNode[3] + rightNode[0]),
            max(leftNode[2] + rightNode[3], leftNode[3] + rightNode[1])
        ]
    
    def build(self, index: int, left: int, right: int) -> None:
        if left == right:
            self.tree[index][3] = self.nums[left]
            return
        mid = (left + right) >> 1
        self.build(2 * index + 1, left, mid)
        self.build(2 * index + 2, mid + 1, right)
        self.maintain(index)

    def update(self, index: int, left: int, right: int, modifiedI: int, val: int) -> None:
        if left == right:
            self.tree[index][3] = max(0, val)
            return
        mid = (left + right) >> 1
        if modifiedI <= mid:
            self.update(2 * index + 1, left, mid, modifiedI, val)
        else:
            self.update(2 * index + 2, mid + 1, right, modifiedI, val)
        self.maintain(index)

    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        self.tree = [[0, 0, 0, 0] for _ in range(len(nums) * 4)]  # 00, 01, 10, 11
        self.nums = nums
        self.build(0, 0, len(nums) - 1)
        ans = 0
        for q, v in queries:
            self.update(0, 0, len(nums) - 1, q, v)
            ans = (ans + self.tree[0][3]) % MOD
        return ans
