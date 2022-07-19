/*
 * @Author: LetMeFly
 * @Date: 2022-07-19 11:02:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-19 11:03:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int M = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            M = max(M, prices[i]);
            ans = max(ans, M - prices[i]);
        }
        return ans;
    }
};