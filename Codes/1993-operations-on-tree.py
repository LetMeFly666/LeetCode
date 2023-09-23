'''
Author: LetMeFly
Date: 2023-09-23 09:26:03
LastEditors: LetMeFly
LastEditTime: 2023-09-23 09:54:53
'''
from typing import List

class LockingTree:

    def __init__(self, parent: List[int]):
        self.parent = parent
        self.lockUser = [0] * len(parent)
        self.child = [[] for _ in range(len(parent))]
        for i in range(1, len(parent)):
            self.child[parent[i]].append(i)


    def lock(self, num: int, user: int) -> bool:
        if self.lockUser[num]:
            return False
        self.lockUser[num] = user
        return True


    def unlock(self, num: int, user: int) -> bool:
        if self.lockUser[num] == user:
            self.lockUser[num] = 0
            return True
        return False


    def upgrade(self, num: int, user: int) -> bool:
        if not self.lockUser[num] and not self.__hasLockedParent__(num) and self.__hasLockedChildAndUnlock__(num):
            self.lockUser[num] = user
            return True
        return False
    

    def __hasLockedParent__(self, num: int) -> bool:
        while self.parent[num] != -1:
            num = self.parent[num]
            if self.lockUser[num]:
                return True
        return False
    

    def __hasLockedChildAndUnlock__(self, num: int) -> bool:
        hasLockedChild = False
        if self.lockUser[num]:
            self.lockUser[num] = 0
            hasLockedChild = True
        for thisChild in self.child[num]:
            hasLockedChild |= self.__hasLockedChildAndUnlock__(thisChild)
        return hasLockedChild


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)