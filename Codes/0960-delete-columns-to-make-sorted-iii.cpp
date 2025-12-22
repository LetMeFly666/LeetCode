/*
 * @Author: LetMeFly
 * @Date: 2025-12-22 22:28:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-22 22:33:00
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool can(vector<string>& strs, int b, int a) {
        for (string& s : strs) {
            if (s[b] < s[a]) {
                return false;
            }
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        vector<int> dp(m);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < dp[i] && can(strs, i, j)) {
                    dp[j] = dp[i];
                }
                dp[j]++;
            }
        }
        return m - *max_element(dp.begin(), dp.end());
    }
};