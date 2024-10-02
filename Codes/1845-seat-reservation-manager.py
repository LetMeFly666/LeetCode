'''
Author: LetMeFly
Date: 2024-10-02 22:34:28
LastEditors: LetMeFly
LastEditTime: 2024-10-02 22:51:04
'''
import heapq

class SeatManager:
    def __init__(self, n: int):
        self.q = list(range(1, n + 1))
        heapq.heapify(self.q)

    def reserve(self) -> int:
        return heapq.heappop(self.q)

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.q, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)