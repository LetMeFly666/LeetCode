'''
Author: LetMeFly
Date: 2023-03-02 09:35:36
LastEditors: LetMeFly
LastEditTime: 2023-03-02 09:40:14
'''
class Solution:
    def printBin(self, num: float) -> str:
        ans = "0."
        while True:
            num *= 2
            thisVal = num >= 1
            ans += chr(ord('0') + thisVal)
            num -= thisVal
            if num == 0:
                return ans
            if len(ans) == 32:
                return "ERROR"