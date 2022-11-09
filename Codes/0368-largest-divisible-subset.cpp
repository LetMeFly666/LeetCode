/*
 * @Author: LetMeFly
 * @Date: 2022-10-08 14:52:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-08 15:18:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxLength = 0;
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                maxVal = nums[i];
            }
        }
        vector<int> ans(maxLength);
        for (int i = n - 1; i >= 0; i--) {
            if (maxVal % nums[i] == 0 && dp[i] == maxLength) {
                ans[--maxLength] = nums[i];
                maxVal = nums[i];
                if (!maxLength)
                    break;
            }
        }
        return ans;
    }
};