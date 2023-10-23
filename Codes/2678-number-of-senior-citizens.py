'''
Author: LetMeFly
Date: 2023-10-23 13:22:50
LastEditors: LetMeFly
LastEditTime: 2023-10-23 13:30:13
'''
from typing import List

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(((ord(d[11]) - ord('0')) * 10 + (ord(d[12]) - ord('0')) > 60) for d in details)