'''
Author: LetMeFly
Date: 2024-10-15 23:54:34
LastEditors: LetMeFly
LastEditTime: 2024-10-15 23:55:49
'''
class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        cnt = [0, 0]
        for layer in range(1, 1000000):
            cnt[layer % 2] += layer
            if not ((cnt[0] <= red and cnt[1] <= blue) or (cnt[0] <= blue and cnt[1] <= red)):
                return layer - 1
        return -1  # Fake Return