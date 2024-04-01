'''
Author: LetMeFly
Date: 2024-04-01 16:35:17
LastEditors: LetMeFly
LastEditTime: 2024-04-01 16:37:02
'''
from collections import deque

class Solution:
    def finalString(self, s: str) -> str:
        q = deque()
        appendleft = False
        for c in s:
            if c == 'i':
                appendleft = not appendleft
                continue
            if appendleft:
                q.appendleft(c)
            else:
                q.append(c)
        return ''.join(q)[::-1] if appendleft else ''.join(q)
