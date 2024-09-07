/*
 * @Author: LetMeFly
 * @Date: 2024-09-06 12:35:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-06 12:58:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
            for (int l = 0; l <= k; l++) {
                for (int j = 0; j < i; j++) {
                    int diff = nums[i] != nums[j];
                    if (l - diff >= 0) {
                        dp[i][l] = max(dp[i][l], dp[j][l - diff] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int l = 0; l <= k; l++) {
                ans = max(ans, dp[i][l]);
            }
        }
        return ans;
    }
};