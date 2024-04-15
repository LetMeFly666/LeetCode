'''
Author: LetMeFly
Date: 2024-04-15 17:13:49
LastEditors: LetMeFly
LastEditTime: 2024-04-15 17:14:51
'''
class MyHashMap:
    def __init__(self):
        self.hashMap = [-1] * 1_000_001

    def put(self, key: int, value: int) -> None:
        self.hashMap[key] = value

    def get(self, key: int) -> int:
        return self.hashMap[key]

    def remove(self, key: int) -> None:
        self.hashMap[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)