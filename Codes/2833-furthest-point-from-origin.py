'''
Author: LetMeFly
Date: 2026-04-24 20:58:31
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-24 21:02:38
'''
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        flex = diff = 0
        for c in moves:
            if c == 'L':
                diff -= 1
            elif c == 'R':
                diff += 1
            else:
                flex += 1
        return flex + diff if diff > 0 else flex - diff
