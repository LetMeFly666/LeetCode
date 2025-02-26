'''
Author: LetMeFly
Date: 2025-02-25 22:52:18
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-25 23:31:26
'''
from typing import List, Any
import random


MAX_LEVEL = 15
P = 0.5

class SkiplistNode:
    def __init__(self, v: int, level: int):
        self.value = v
        self.next: List[SkiplistNode] = [None] * level

class Skiplist:
    def __init__(self):
        self.head = SkiplistNode(-1, MAX_LEVEL)
        self.level = 0
    
    def __randLevel(self):
        ans = 1
        while ans < MAX_LEVEL and random.random() < P:
            ans += 1
        return ans

    def search(self, target: int) -> bool:
        p = self.head
        for i in range(self.level - 1, -1, -1):
            while p.next[i] and p.next[i].value < target:
                p = p.next[i]
        p = p.next[0]
        # return p and p.value == target  # 不可！p为None的化这一行会return None而不是False！
        return p is not None and p.value == target

    def add(self, num: int) -> None:
        newLevel = self.__randLevel()
        update = [self.head] * newLevel
        p = self.head
        for i in range(self.level - 1, -1, -1):
            while p.next[i] and p.next[i].value < num:
                p = p.next[i]
            if i < newLevel:
                update[i] = p
        
        self.level = max(self.level, newLevel)
        newNode = SkiplistNode(num, newLevel)
        for i in range(newLevel):
            newNode.next[i] = update[i].next[i]
            update[i].next[i] = newNode

    def erase(self, num: int) -> bool:
        update: List[SkiplistNode | Any] = [None] * self.level
        p = self.head
        for i in range(self.level - 1, -1, -1):
            while p.next[i] and p.next[i].value < num:
                p = p.next[i]
            update[i] = p
        
        p = p.next[0]
        if not p or p.value != num:
            return False
        
        for i in range(self.level):
            if update[i].next[i] != p:
                break
            update[i].next[i] = p.next[i]
        while self.level > 0 and not self.head.next[self.level - 1]:
            self.level -= 1
        return True


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)