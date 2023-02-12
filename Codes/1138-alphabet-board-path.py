'''
Author: LetMeFly
Date: 2023-02-12 09:35:01
LastEditors: LetMeFly
LastEditTime: 2023-02-12 10:03:14
'''
from typing import Tuple


def c2p(c: str) -> Tuple[int, int]:
    th = ord(c) - ord('a')
    return th // 5, th % 5

class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        ans = []
        nowY, nowX = 0, 0
        for c in target:
            newY, newX = c2p(c)
            if newY < nowY:
                ans.append('U' * (nowY - newY))
            if newX < nowX:
                ans.append('L' * (nowX - newX))
            if newY > nowY:
                ans.append('D' * (newY - nowY))
            if newX > nowX:
                ans.append('R' * (newX - nowX))
            ans.append('!')
            nowY, nowX = newY, newX
        return "".join(ans)