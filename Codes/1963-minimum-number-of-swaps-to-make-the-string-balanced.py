'''
Author: LetMeFly
Date: 2025-03-17 12:18:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-17 12:18:42
'''
class Solution:
    def minSwaps(self, s: str) -> int:
        zuoQianYou = zuo = 0
        for c in s:
            if c == '[':
                zuo += 1
            else:
                if zuo:
                    zuo -= 1
                else:
                    zuoQianYou += 1
        return (zuoQianYou + 1) // 2