/*
 * @Author: LetMeFly
 * @Date: 2022-07-19 11:13:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-19 11:13:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};