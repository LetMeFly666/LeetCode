from sortedcontainers import SortedSet 

class SmallestInfiniteSet:

    def __init__(self):
        self.continuousSmallest = 1
        self.added = SortedSet()


    def popSmallest(self) -> int:
        if self.added:
            return -self.added.pop()
        self.continuousSmallest += 1
        return self.continuousSmallest - 1


    def addBack(self, num: int) -> None:
        if num >= self.continuousSmallest:
            return
        self.added.add(-num)



# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)