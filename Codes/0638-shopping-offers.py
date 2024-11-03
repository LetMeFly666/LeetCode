'''
Author: LetMeFly
Date: 2024-11-03 14:55:44
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-03 15:13:29
'''
from typing import List, Tuple
from functools import cache

"""
# FirstTry: TypeError: unhashable type: 'list'
class Solution:
    @cache
    def dfs(self, needs: List[int]) -> int:
        ans = sum(self.price[i] * needs[i] for i in range(len(needs)))
        for thisSpecial in self.special:
            if all(thisSpecial[i] <= needs[i] for i in range(len(needs))):
                for i in range(len(needs)):
                    needs[i] -= thisSpecial[i]
                ans = min(ans, self.dfs(needs))
                for i in range(len(needs)):
                    needs[i] += thisSpecial[i]
        return ans

    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        self.price = price
        self.special = special
        return self.dfs(needs)
"""

class Solution:
    @cache
    def dfs(self, needs: Tuple[int]) -> int:
        ans = sum(self.price[i] * needs[i] for i in range(len(needs)))
        for thisSpecial in self.special:
            if any(thisSpecial[i] > needs[i] for i in range(len(needs))):
                continue
            newNeedsList = list(needs)
            for i in range(len(newNeedsList)):
                newNeedsList[i] -= thisSpecial[i]
            ans = min(ans, thisSpecial[-1] + self.dfs(tuple(newNeedsList)))
        return ans

    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        self.price = price
        self.special = special
        return self.dfs(tuple(needs))