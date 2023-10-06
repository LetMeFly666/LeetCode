/*
 * @Author: LetMeFly
 * @Date: 2023-10-06 12:08:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-06 12:11:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i] - fee);
        }
        return sell;
    }
};