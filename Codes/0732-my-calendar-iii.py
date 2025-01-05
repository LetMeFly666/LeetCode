'''
Author: LetMeFly
Date: 2025-01-05 21:34:19
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-05 21:38:20
'''
from collections import defaultdict

class MyCalendarThree:

    def __init__(self):
        self.tree = defaultdict(int)
        self.lazy = defaultdict(int)

    def update(self, start: int, end: int, index: int, l: int, r: int) -> None:
        if l > end or start > r:
            return
        if start <= l and r <= end:
            self.tree[index] += 1
            self.lazy[index] += 1
        else:
            mid = (l + r) >> 1
            self.update(start, end, index * 2 + 1, l, mid)
            self.update(start, end, index * 2 + 2, mid + 1, r)
            self.tree[index] = self.lazy[index] + max(self.tree[index * 2 + 1], self.tree[index * 2 + 2])

    def book(self, startTime: int, endTime: int) -> int:
        self.update(startTime, endTime - 1, 0, 0, 1000000000)
        return self.tree[0]


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)