/*
 * @Author: LetMeFly
 * @Date: 2026-08-03 18:28:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-03 18:52:09
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 3);
        int suffix = 0;
        for (int i = stoneValue.size() - 2; i >= 0; i--) {
            dp[i] = INT_MIN;
            suffix += stoneValue[i];
            for (int j = 1; j <= 3; j++) {
                dp[i] = max(dp[i], suffix - dp[i + j]);
            }
        }

        int diff = dp[0] - (suffix - dp[0]);
        return diff > 0 ? "Alice" : diff ? "Bob" : "Tie";
    }
};
