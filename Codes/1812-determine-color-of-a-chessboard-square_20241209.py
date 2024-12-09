'''
Author: LetMeFly
Date: 2024-12-09 17:06:45
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-09 17:07:19
'''
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return ord(coordinates[0]) % 2 != ord(coordinates[1]) % 2