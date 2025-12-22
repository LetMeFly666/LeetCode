/*
 * @Author: LetMeFly
 * @Date: 2025-12-22 22:28:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-22 22:43:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool can(vector<string>& strs, int i, int j) {
        for (string& s : strs) {
            if (s[i] < s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        vector<int> dp(m);
        for (int i = 0; i < m; i++) {  // 一定要从0开始！！要不然dp[0]恒为0
            for (int j = 0; j < i; j++) {
                if (dp[j] > dp[i] && can(strs, i, j)) {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
        }
        return m - *max_element(dp.begin(), dp.end());
    }
};