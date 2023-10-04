/*
 * @Author: LetMeFly
 * @Date: 2023-10-04 10:55:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-04 11:03:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1);
        buy[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // buy[i] = *max_element(sell.begin(), sell.begin() + i) - prices[i];  // 不超过前i-1 次买卖才有意义
            // sell[i] = *max_element(buy.begin(), buy.begin() + i) + prices[i];
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};