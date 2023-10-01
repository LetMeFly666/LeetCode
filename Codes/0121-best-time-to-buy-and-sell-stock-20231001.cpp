/*
 * @Author: LetMeFly
 * @Date: 2023-10-01 17:54:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-01 17:55:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, m = prices[0];
        for (int t : prices) {
            m = min(m, t);
            ans = max(ans, t - m);
        }
        return ans;
    }
};