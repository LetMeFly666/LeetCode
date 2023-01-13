'''
Author: LetMeFly
Date: 2023-01-13 15:37:31
LastEditors: LetMeFly
LastEditTime: 2023-01-13 15:47:59
'''
from typing import Counter


if False:  # 方法一
    class Solution:
        def rearrangeCharacters(self, s: str, target: str) -> int:
            cntS = Counter(s)
            cntT = Counter(target)
            ans = len(s)
            for i in range(26):
                thisChar = chr(ord('a') + i)
                if cntT.get(thisChar):
                    ans = min(ans, cntS.get(thisChar, 0) // cntT.get(thisChar))
            return ans

class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cntS = Counter(s)
        ans = len(s)
        for thisChar, thisTimes in Counter(target).items():
            ans = min(ans, cntS.get(thisChar, 0) // thisTimes)
        return ans
