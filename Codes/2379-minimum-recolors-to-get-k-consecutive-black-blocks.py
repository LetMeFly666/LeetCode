'''
Author: LetMeFly
Date: 2023-03-09 09:08:28
LastEditors: LetMeFly
LastEditTime: 2023-03-09 09:10:38
'''
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        cnt = 0
        for i in range(k):
            cnt += blocks[i] == 'W'
        ans = cnt
        for i in range(k, len(blocks)):
            cnt += blocks[i] == 'W'
            cnt -= blocks[i - k] == 'W'
            ans = min(ans, cnt)
        return ans