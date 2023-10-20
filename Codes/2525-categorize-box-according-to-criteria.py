'''
Author: LetMeFly
Date: 2023-10-20 12:09:52
LastEditors: LetMeFly
LastEditTime: 2023-10-20 12:11:46
'''
dic = ['Neither', 'Heavy', 'Bulky', 'Both']
class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        bulky = length >= 10000 or width >= 10000 or height >= 10000 or length * width * height >= 1000000000
        heavy = mass >= 100
        return dic[bulky * 2 + heavy]
