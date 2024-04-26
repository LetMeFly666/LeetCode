'''
Author: LetMeFly
Date: 2024-04-26 11:14:45
LastEditors: LetMeFly
LastEditTime: 2024-04-26 11:17:39
'''
from bisect import bisect_right


class SnapshotArray:
    def __init__(self, length: int):
        self.a = [[] for _ in range(length)]
        self.snapId = 0

    def set(self, index: int, val: int) -> None:
        self.a[index].append((self.snapId, val))

    def snap(self) -> int:
        self.snapId += 1
        return self.snapId - 1

    def get(self, index: int, snap_id: int) -> int:
        it = bisect_right(self.a[index], (snap_id + 1, -1))
        return 0 if not it else self.a[index][it - 1][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)