'''
Author: LetMeFly
Date: 2023-12-31 12:36:12
LastEditors: LetMeFly
LastEditTime: 2023-12-31 12:38:42
'''
class Solution:
    def ifRunNian(self, y: int) -> bool:
        if y % 100 == 0:
            return y % 400 == 0
        return y % 4 == 0
    
    def dayOfYear(self, date: str) -> int:
        dayOfMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        y, m, d = map(int, date.split('-'))
        if self.ifRunNian(y):
            dayOfMonth[1] = 29
        ans = 0
        for i in range(1, m):
            ans += dayOfMonth[i - 1]
        ans += d
        return ans
