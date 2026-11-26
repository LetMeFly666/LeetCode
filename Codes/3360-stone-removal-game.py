'''
Author: LetMeFly
Date: 2026-11-26 07:52:43
LastEditors: LetMeFly.xyz
LastEditTime: 2026-11-26 08:04:25
'''
class Solution:
    def canAliceWin(self, n: int) -> bool:
        state, need = False, 10
        while n >= need:
            n -= need
            need -= 1
            state = not state
        return state
