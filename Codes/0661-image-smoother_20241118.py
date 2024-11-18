'''
Author: LetMeFly
Date: 2024-11-18 21:10:17
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-18 21:12:52
'''
from typing import List

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        ans = [[0 for _ in range(len(img[0]))] for _ in range(len(img))]
        for i in range(len(img)):
            for j in range(len(img[0])):
                cnt, s = 0, 0
                for dx in range(-1, 2):
                    for dy in range(-1, 2):
                        x, y = i + dx, j + dy
                        if 0 <= x < len(img) and 0 <= y < len(img[0]):
                            cnt += 1
                            s += img[x][y]
                ans[i][j] = s // cnt
        return ans