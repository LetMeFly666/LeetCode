/*
 * @Author: LetMeFly
 * @Date: 2023-10-05 10:41:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-05 10:45:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int buy = -prices[0], sell = 0, sellBefore = 0;
        for (int i = 1; i < prices.size(); i++) {
            int newBuy = max(buy, sellBefore - prices[i]);
            int newSell = max(sell, buy + prices[i]);
            int newSellBefore = sell;
            buy = newBuy, sell = newSell, sellBefore = newSellBefore;
        }
        return sell;
    }
};