'''
Author: LetMeFly
Date: 2025-01-03 13:11:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-03 13:16:04
'''
class MyCalendarTwo:

    def __init__(self):
        self.booked = []
        self.overlap = []

    def book(self, startTime: int, endTime: int) -> bool:
        if any(endTime > s and e > startTime for s, e in self.overlap):
            return False
        for s, e in self.booked:
            if endTime > s and e > startTime:
                self.overlap.append((max(startTime, s), min(endTime, e)))
        self.booked.append((startTime, endTime))
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)