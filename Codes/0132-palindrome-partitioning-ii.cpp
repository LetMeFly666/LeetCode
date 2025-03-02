/*
 * @Author: LetMeFly
 * @Date: 2025-03-02 12:02:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-02 12:26:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isOk(s.size(), vector<bool>(s.size(), true));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                isOk[i][j] = s[i] == s[j] && isOk[i + 1][j - 1];
            }
        }

        vector<int> dp(s.size(), 1000000);
        for (int i = 0; i < s.size(); i++) {
            if (isOk[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isOk[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};