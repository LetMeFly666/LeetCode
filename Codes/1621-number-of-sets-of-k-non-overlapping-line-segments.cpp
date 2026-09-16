/*
 * @Author: LetMeFly
 * @Date: 2026-09-16 16:56:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-16 17:17:29
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<ll>> dp(n, vector<ll>(k + 1));
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[i][j] = max(dp[i][j], dp[i][])
            }
        }
    }
};
