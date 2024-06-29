'''
Author: LetMeFly
Date: 2024-06-29 17:12:29
LastEditors: LetMeFly
LastEditTime: 2024-06-29 17:13:55
'''
class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        for loc in range(len(num) - 1, -1, -1):
            if num[loc] != '0':
                break
        return num[:loc + 1]