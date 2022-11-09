/*
 * @Author: LetMeFly
 * @Date: 2022-09-18 08:55:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-18 09:09:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int> buy(prices.size(), 0);
        // vector<int> sell(prices.size(), 0);
        // vector<int> none(prices.size(), 0);
        int buy = -prices[0];
        int sell = 0;
        int none = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int newBuy = max(buy, none - prices[i]);
            int newSell = buy + prices[i];
            int newNone = max(none, sell);
            buy = newBuy;
            sell = newSell;
            none = newNone;
        }
        return max(sell, none);
    }
};