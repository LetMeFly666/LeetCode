/*
 * @Author: LetMeFly
 * @Date: 2022-07-20 11:55:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-20 12:15:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
        int buy2 = INT_MIN, sell2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            buy1 = max(buy1, 0 + (-prices[i]));
            sell1 = max(sell1, buy1 + (prices[i]));
            buy2 = max(buy2, sell1 + (-prices[i]));
            sell2 = max(sell2, buy2 + (prices[i]));
        }
        return sell2;
    }
};
#else  // FirstTry
// SecondTry  // 改变变量初始值为第一天进行了所有的交易
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < prices.size(); i++) {
            buy1 = max(buy1, 0 + (-prices[i]));
            sell1 = max(sell1, buy1 + (prices[i]));
            buy2 = max(buy2, sell1 + (-prices[i]));
            sell2 = max(sell2, buy2 + (prices[i]));
        }
        return sell2;
    }
};
#endif  // FirstTry