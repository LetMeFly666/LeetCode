'''
Author: LetMeFly
Date: 2024-04-07 17:01:19
LastEditors: LetMeFly
LastEditTime: 2024-04-07 17:26:54
'''
from typing import List


class KingNode:
    def __init__(self, name) -> None:
        self.name = name
        self.childs = []
        self.isAlive = True


class ThroneInheritance:
    def _dfs(self, root: KingNode) -> None:
        if root.isAlive:
            self.tempForInheritanceOrder.append(root.name)
        for child in root.childs:
            self._dfs(child)

    def __init__(self, kingName: str):
        self.name2node = dict()
        self.root = KingNode(kingName)
        self.name2node[kingName] = self.root

    def birth(self, parentName: str, childName: str) -> None:
        child = KingNode(childName)
        self.name2node[childName] = child
        self.name2node[parentName].childs.append(child)

    def death(self, name: str) -> None:
        self.name2node[name].isAlive = False

    def getInheritanceOrder(self) -> List[str]:
        self.tempForInheritanceOrder = []
        self._dfs(self.root)
        return self.tempForInheritanceOrder


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()