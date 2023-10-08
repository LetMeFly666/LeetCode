'''
Author: LetMeFly
Date: 2023-10-08 12:28:55
LastEditors: LetMeFly
LastEditTime: 2023-10-08 12:34:54
'''
from sortedcontainers import SortedList


class StockPrice:

    def __init__(self):
        self.ma = {}
        self.se = SortedList()
        self.Mtime = 0


    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.ma:
            self.se.discard(self.ma[timestamp])
        self.ma[timestamp] = price
        self.se.add(price)
        self.Mtime = max(self.Mtime, timestamp)


    def current(self) -> int:
        return self.ma[self.Mtime]


    def maximum(self) -> int:
        return self.se[-1]


    def minimum(self) -> int:
        return self.se[0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()