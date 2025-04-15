'''
Author: LetMeFly
Date: 2025-04-15 10:28:55
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-15 10:34:14
'''
from typing import List

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        # return sum(abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[j] - arr[k]) <= c for k in range(j + 1, len(arr)) for j in range(i + 1, len(arr)) for i in range(len(arr)))
        return sum(abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c for i in range(len(arr)) for j in range(i + 1, len(arr)) for k in range(j + 1, len(arr)))