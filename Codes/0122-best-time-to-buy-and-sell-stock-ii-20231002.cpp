/*
 * @Author: LetMeFly
 * @Date: 2023-10-02 14:01:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-02 14:09:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};