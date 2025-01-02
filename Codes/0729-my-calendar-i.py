'''
Author: LetMeFly
Date: 2025-01-02 16:16:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-02 16:22:15
'''
# 产生交集：!(e1 <= s2 || e2 <= s1) 等价于 e1 > s2 && e2 > s1
class MyCalendar:

    def __init__(self):
        self.bookList = []

    def book(self, startTime: int, endTime: int) -> bool:
        if any(e > startTime and endTime > s for s, e in self.bookList):
            return False
        self.bookList.append((startTime, endTime))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)