'''
Author: LetMeFly
Date: 2023-04-17 10:04:18
LastEditors: LetMeFly
LastEditTime: 2023-04-17 10:13:48
'''
dayPerMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

class Solution:
    def stringToInt(self, s: str) -> int:
        m, d = map(int, s.split('-'))
        ans = 0
        for i in range(1, m):
            ans += dayPerMonth[i - 1]
        ans += d
        return ans

    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        aa = self.stringToInt(arriveAlice)
        la = self.stringToInt(leaveAlice)
        ab = self.stringToInt(arriveBob)
        lb = self.stringToInt(leaveBob)
        if aa > ab:
            aa, ab = ab, aa
            la, lb = lb, la
        if ab > la:
            return 0
        return min(la, lb) - ab + 1