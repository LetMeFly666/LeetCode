/*
 * @Author: LetMeFly
 * @Date: 2026-11-27 12:45:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-27 12:48:58
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> dp(budget + 1);
        int cheap = items[0][1];
        for (vector<int>& item : items) {
            int factor = item[0], price = item[1];
            cheap = min(cheap, price);
            int get = 0;
            for (vector<int>& other : items) {
                if (other[1] % factor == 0) {
                    get++;
                }
            }
            for (int i = budget; i >= price; i--) {
                dp[i] = max(dp[i], dp[i - price] + get);
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / cheap);
        }
        return ans;
    }
};
