/*
 * @Author: LetMeFly
 * @Date: 2024-10-25 23:50:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-25 23:56:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<bool> dp(rewardValues.back() * 2);
        dp[0] = true;
        for (int t : rewardValues) {  // [t + 0, t + t - 1]
            for (int x = t * 2 - 1; x >= t; x--) {
                dp[x] = dp[x] | dp[x - t];  // dp[x] |= dp[x - t];
            }
        }
        int ans = dp.size() - 1;
        while (!dp[ans]) {
            ans--;
        }
        return ans;
    }
};