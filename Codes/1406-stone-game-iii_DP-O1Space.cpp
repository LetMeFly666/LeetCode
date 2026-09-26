/*
 * @Author: LetMeFly
 * @Date: 2026-08-03 18:28:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-03 19:01:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int dp3[3] = {0};
        int suffix = 0;
        for (int i = stoneValue.size() - 1; i >= 0; i--) {
            int dp = INT_MIN;
            suffix += stoneValue[i];
            for (int j = 0; j < 3; j++) {
                dp = max(dp, suffix - dp3[j]);
            }
            dp3[2] = dp3[1], dp3[1] = dp3[0], dp3[0] = dp;
        }
        
        int diff = dp3[0] - (suffix - dp3[0]);
        return diff > 0 ? "Alice" : diff ? "Bob" : "Tie";
    }
};
