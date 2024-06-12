/*
 * @Author: LetMeFly
 * @Date: 2024-06-12 11:03:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-12 11:05:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rest = purchaseAmount % 10;
        purchaseAmount -= rest;
        if (rest >= 5) {
            purchaseAmount += 10;
        }
        return 100 - purchaseAmount;
    }
};