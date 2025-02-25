'''
Author: LetMeFly
Date: 2025-02-24 09:09:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-24 09:11:29
'''
from typing import List

class OrderedStream:

    def __init__(self, n: int):
        self.n = n
        self.ptr = 1
        self.v = [None] * (n + 1)

    def insert(self, idKey: int, value: str) -> List[str]:
        self.v[idKey] = value
        if idKey != self.ptr:
            return []
        ans = []
        while self.ptr <= self.n and self.v[self.ptr]:
            ans.append(self.v[self.ptr])
            self.ptr += 1
        return ans


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)