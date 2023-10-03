/*
 * @Author: LetMeFly
 * @Date: 2023-10-03 17:15:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-03 17:21:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            int buy1new = max(buy1, -prices[i]);
            int sell1new = max(sell1,  buy1 + prices[i]);
            int buy2new = max(buy2, sell1 - prices[i]);
            int sell2new = max(sell2, buy2 + prices[i]);
            buy1 = buy1new, sell1 = sell1new, buy2 = buy2new, sell2 = sell2new;
        }
        return sell2;
    }
};