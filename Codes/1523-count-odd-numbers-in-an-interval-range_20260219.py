'''
Author: LetMeFly
Date: 2026-02-19 17:59:08
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-19 18:00:11
'''
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if low % 2:
            low -= 1
        if high % 2:
            high += 1
        return (high - low) // 2