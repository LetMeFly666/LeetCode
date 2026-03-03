'''
Author: LetMeFly
Date: 2026-03-03 20:11:50
LastEditors: LetMeFly.xyz
LastEditTime: 2026-03-03 20:13:10
'''
class Solution:
    def invert(self, n: str) -> str:
        return '1' if n == '0' else '0'
    
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return '0'
        len = 1 << n - 1
        half = len >> 1
        if k == half + 1:
            return '1'
        elif k < half:
            return self.findKthBit(n - 1, k)
        else:
            return self.invert(self.findKthBit(n - 1, n - k + 1))