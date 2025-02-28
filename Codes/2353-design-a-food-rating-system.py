'''
Author: LetMeFly
Date: 2025-02-28 11:30:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-28 12:28:00
'''
from typing import List
from sortedcontainers import SortedList
from collections import defaultdict


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.f2cs = dict()
        self.c2rf = defaultdict(SortedList)
        for i in range(len(foods)):
            self.f2cs[foods[i]] = (cuisines[i], ratings[i])
            self.c2rf[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.f2cs[food]
        self.f2cs[food] = (cuisine, newRating)
        self.c2rf[cuisine].discard((-rating, food))
        self.c2rf[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.c2rf[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)