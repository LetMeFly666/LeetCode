'''
Author: LetMeFly
Date: 2024-10-22 18:32:26
LastEditors: LetMeFly
LastEditTime: 2024-10-22 18:41:22
'''
from typing import List

class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        return sum((hours[i] + hours[j]) % 24 == 0 for i in range(len(hours)) for j in range(i + 1, len(hours)))

if __name__ == '__main__':
    l = ((i, j) for i in range(3) for j in range(3))
    for i, j in l:
        print(i, j)
    """
    0 0
    0 1
    0 2
    1 0
    1 1
    1 2
    2 0
    2 1
    2 2
    """