/*
 * @Author: LetMeFly
 * @Date: 2022-10-18 12:56:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-18 13:16:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (int& t : nums)
            s += t;
        if (s % 2)
            return false;
        s /= 2;
        vector<vector<bool>> dp(n, vector<bool>(s + 1, false));  // dp[i][j]：0~i能否构成j
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= s; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i] && dp[i][j - nums[i]])
                    dp[i][j] = true;
            }
        }
        return dp[n - 1][s];
    }
};
#else  // FisrstTry
// SecondTry  // Copy
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};
#endif  // FirstTry