'''
Author: LetMeFly
Date: 2023-05-02 10:09:30
LastEditors: LetMeFly
LastEditTime: 2023-05-02 10:20:06
'''
from typing import List

class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        se = set()
        i = 0
        while True:
            first = x ** i
            if first > bound:
                break

            j = 0
            while True:
                second = y ** j
                s = first + second
                if s > bound:
                    break
                se.add(s)
                if y == 1:
                    break
                j += 1

            if x == 1:
                break
            i += 1
        return list(se)