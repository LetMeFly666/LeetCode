'''
Author: LetMeFly
Date: 2026-03-01 19:50:43
LastEditors: LetMeFly.xyz
LastEditTime: 2026-03-01 19:52:13
'''
class Solution:
    def minPartitions(self, n: str) -> int:
        return ord(max(n)) - ord('0')  # 记得python str不能直接相减