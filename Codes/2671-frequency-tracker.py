'''
Author: LetMeFly
Date: 2024-03-21 22:18:03
LastEditors: LetMeFly
LastEditTime: 2024-03-21 22:21:40
'''
from collections import defaultdict

class FrequencyTracker:

    def __init__(self):
        self.val2times = defaultdict(int)
        self.times2times = defaultdict(int)

    def add(self, number: int, diff=1) -> None:
        originalTimes = self.val2times[number]
        self.val2times[number] += diff
        self.times2times[originalTimes] -= 1
        self.times2times[originalTimes + diff] += 1

    def deleteOne(self, number: int) -> None:
        if self.val2times[number]:
            self.add(number, -1)

    def hasFrequency(self, frequency: int) -> bool:
        return self.times2times[frequency] != 0


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)