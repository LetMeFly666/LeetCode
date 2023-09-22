'''
Author: LetMeFly
Date: 2023-09-22 13:14:34
LastEditors: LetMeFly
LastEditTime: 2023-09-22 13:17:09
'''
from typing import List

class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        if money > children * 8:
            return children - 1
        if money == children * 8 - 4:
            return children - 2
        return (money - children) // 7