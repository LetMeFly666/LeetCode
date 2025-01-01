'''
Author: LetMeFly
Date: 2025-01-01 18:49:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-01 18:50:23
'''
class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return '-'.join(bin(int(s))[2:] for s in date.split('-'))