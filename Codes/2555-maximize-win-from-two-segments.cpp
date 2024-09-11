/*
 * @Author: LetMeFly
 * @Date: 2024-09-11 14:16:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-11 14:23:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<int> dp(prizePositions.size() + 1);
        int ans = 0;
        for (int l = 0, r = 0; r < prizePositions.size(); r++) {
            while (prizePositions[r] - prizePositions[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1 + dp[l]);
            dp[r + 1] = max(dp[r], r - l + 1);
        }
        return ans;
    }
};