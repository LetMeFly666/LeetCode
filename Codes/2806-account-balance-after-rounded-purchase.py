'''
Author: LetMeFly
Date: 2024-06-12 11:06:24
LastEditors: LetMeFly
LastEditTime: 2024-06-12 11:06:24
'''
class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        rest = purchaseAmount % 10
        purchaseAmount -= rest
        if rest >= 5:
            purchaseAmount += 10
        return 100 - purchaseAmount