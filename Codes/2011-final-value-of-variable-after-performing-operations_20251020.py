'''
Author: LetMeFly
Date: 2025-10-20 18:44:35
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-20 18:47:35
'''
from typing import List

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if op[1] == '+' else -1 for op in operations)