/*
 * @Author: LetMeFly
 * @Date: 2023-01-21 10:27:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-21 10:36:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[3] = {1, 0, 1};
        for (int i = 1; i < obstacles.size(); i++) {
            int minStep = 999999;
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) {
                    dp[j] = 999999;
                }
                else {
                    minStep = min(minStep, dp[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] != j + 1) {
                    dp[j] = min(dp[j], minStep + 1);
                }
            }
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};