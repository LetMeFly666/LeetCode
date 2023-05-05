/*
 * @Author: LetMeFly
 * @Date: 2023-05-05 20:03:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-05 20:05:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 0, M = -1, lastTime = 0;
        for (auto& log : logs) {
            if (log[1] - lastTime > M) {
                M = log[1] - lastTime;
                ans = log[0];
            }
            else if (log[1] - lastTime == M) {
                ans = min(ans, log[0]);
            }
            lastTime = log[1];
        }
        return ans;
    }
};