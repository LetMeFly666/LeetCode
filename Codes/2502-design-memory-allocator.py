'''
Author: LetMeFly
Date: 2025-02-25 16:19:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-25 16:34:50
'''
class Allocator:

    def __init__(self, n: int):
        self.v = [None] * n

    def allocate(self, size: int, mID: int) -> int:
        l, cnt = -1, 0
        for r in range(len(self.v)):
            if self.v[r]:
                l, cnt = r, 0
                continue
            cnt += 1
            if cnt == size:
                for i in range(l + 1, r + 1):
                    self.v[i] = mID
                return l + 1
        return -1

    def freeMemory(self, mID: int) -> int:
        ans = 0
        for i in range(len(self.v)):
            if self.v[i] == mID:
                self.v[i] = 0
                ans += 1
        return ans


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)