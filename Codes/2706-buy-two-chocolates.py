'''
Author: LetMeFly
Date: 2023-12-29 17:03:27
LastEditors: LetMeFly
LastEditTime: 2023-12-29 17:04:42
'''
from typing import List

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        m1, m2 = 1000, 1000
        for p in prices:
            if p < m2:
                m2 = p
                if m1 > m2:
                    m1, m2 = m2, m1
        return money if m1 + m2 > money else money - m1 - m2
