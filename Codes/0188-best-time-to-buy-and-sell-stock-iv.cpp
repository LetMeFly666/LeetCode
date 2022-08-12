/*
 * @Author: LetMeFly
 * @Date: 2022-08-12 10:01:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-12 10:25:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);
        buy[0] = 0, sell[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] + (-prices[i]));
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};