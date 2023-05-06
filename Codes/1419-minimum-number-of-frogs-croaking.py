'''
Author: LetMeFly
Date: 2023-05-06 09:42:53
LastEditors: LetMeFly
LastEditTime: 2023-05-06 09:53:00
'''
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        ma = {'c':0, 'r':1, 'o':2, 'a':3, 'k':4}
        cnt = [0] * 5
        nowFrog = 0
        ans = 0
        for c in croakOfFrogs:
            th = ma[c]
            if not th:  # 新青蛙
                nowFrog += 1
                ans = max(ans, nowFrog)
                cnt[0] += 1
            else:  # 老青蛙
                if not cnt[th - 1]:
                    return -1
                cnt[th - 1] -= 1
                if th == 4:  # 这个青蛙叫完了
                    nowFrog -= 1
                else:
                    cnt[th] += 1
        return ans if not nowFrog else -1