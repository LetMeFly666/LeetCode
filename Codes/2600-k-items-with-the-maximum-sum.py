'''
Author: LetMeFly
Date: 2023-07-05 07:30:55
LastEditors: LetMeFly
LastEditTime: 2023-07-05 07:43:45
'''
class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        ans = 0
        a = [[numOnes, 1], [numZeros, 0], [numNegOnes, -1]]
        for i in range(3):
            thisNum = min(k, a[i][0])
            ans += thisNum * a[i][1]
            k -= thisNum
        return ans
