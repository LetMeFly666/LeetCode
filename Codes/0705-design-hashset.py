'''
Author: LetMeFly
Date: 2024-04-14 09:46:27
LastEditors: LetMeFly
LastEditTime: 2024-04-14 09:47:58
'''
class MyHashSet:  # easy题很多人都是这么写的吧[逃]
    def __init__(self):
        self.hashset = [False] * 1_000_001

    def add(self, key: int) -> None:
        self.hashset[key] = True

    def remove(self, key: int) -> None:
        self.hashset[key] = False

    def contains(self, key: int) -> bool:
        return self.hashset[key]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)