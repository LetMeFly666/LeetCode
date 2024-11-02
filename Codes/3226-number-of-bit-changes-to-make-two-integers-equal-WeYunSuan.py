'''
Author: LetMeFly
Date: 2024-11-02 10:56:41
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-02 10:58:47
'''
class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return (n ^ k).bit_count() if (n | k) == n else -1