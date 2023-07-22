'''
Author: LetMeFly
Date: 2023-07-22 09:02:46
LastEditors: LetMeFly
LastEditTime: 2023-07-22 09:06:36
'''
from typing import List

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        _5, _10 = 0, 0
        for bill in bills:
            if bill == 5:
                _5 += 1
            elif bill == 10:
                if _5:
                    _5 -= 1
                    _10 += 1
                else:
                    return False
            else:
                if _5 and _10:
                    _5 -= 1
                    _10 -= 1
                elif _5 >= 3:
                    _5 -= 3
                else:
                    return False
        return True