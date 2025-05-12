'''
Author: LetMeFly
Date: 2025-05-12 10:20:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-12 13:16:04
'''
from typing import List

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        times = [0] * 10
        for d in digits:
            times[d] += 1
        ans = []
        for i in range(100, 1000, 2):
            thisTimes = [0] * 10
            tmp = i
            while tmp:
                thisTimes[tmp % 10] += 1
                tmp //= 10
            ok = True
            for j in range(10):
                if thisTimes[j] > times[j]:
                    ok = False
                    break
            if ok:
                ans.append(i)
        return sorted(ans)
