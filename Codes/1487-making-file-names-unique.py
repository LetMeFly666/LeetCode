'''
Author: LetMeFly
Date: 2023-03-03 11:03:26
LastEditors: LetMeFly
LastEditTime: 2023-03-03 11:09:17
'''
from typing import List

class Solution:
    def nameAndSuffix(self, name: str, suffix: int) -> str:
        if not suffix:
            return name
        else:
            return name + '(' + str(suffix) + ')'

    def getFolderNames(self, names: List[str]) -> List[str]:
        ma = {}
        ans = []
        for name in names:
            if name not in ma:
                ans.append(name)
                ma[name] = 1
            else:
                times = ma[name]
                newName = self.nameAndSuffix(name, times)
                while newName in ma:
                    times += 1
                    newName = self.nameAndSuffix(name, times)
                ans.append(newName)
                ma[name] = times + 1
                ma[newName] = 1
        return ans
