'''
Author: LetMeFly
Date: 2023-09-27 18:55:52
LastEditors: LetMeFly
LastEditTime: 2023-09-27 19:08:33
'''
from typing import List

class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        temp = [v for v in restaurants if v[2] >= veganFriendly and v[3] <= maxPrice and v[4] <= maxDistance]
        temp.sort(key=lambda v:(-v[1], -v[0]))
        return [v[0] for v in temp]