'''
Author: LetMeFly
Date: 2024-11-05 09:52:45
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-05 09:53:17
'''
class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        return "Alice" if min(x, y // 4) % 2 else "Bob"