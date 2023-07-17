'''
Author: LetMeFly
Date: 2023-07-17 08:25:32
LastEditors: LetMeFly
LastEditTime: 2023-07-17 08:30:14
'''
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        loc1, loc2 = len(num1) - 1, len(num2) - 1
        add = 0
        ans = ""
        while loc1 >= 0 or loc2 >= 0 or add:
            if loc1 >= 0:
                add += ord(num1[loc1]) - ord('0')
                loc1 -= 1
            if loc2 >= 0:
                add += ord(num2[loc2]) - ord('0')
                loc2 -= 1
            ans = chr(ord('0') + add % 10) + ans
            add //= 10
        return ans