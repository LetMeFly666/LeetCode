'''
Author: LetMeFly
Date: 2026-03-15 10:21:03
LastEditors: LetMeFly.xyz
LastEditTime: 2026-03-15 11:25:58
'''
MOD = 1000000007

class Fancy:
    def __init__(self):
        self.add = 0
        self.mul = 1
        self.vals = []

    def append(self, val: int) -> None:
        self.vals.append((val - self.add + MOD) * pow(self.mul, -1, MOD) % MOD)

    def addAll(self, inc: int) -> None:
        self.add = (self.add + inc) % MOD

    def multAll(self, m: int) -> None:
        self.add = self.add * m % MOD
        self.mul = self.mul * m % MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.vals):
            return -1
        return (self.vals[idx] * self.mul + self.add) % MOD


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)