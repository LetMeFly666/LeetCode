/*
 * @Author: LetMeFly
 * @Date: 2026-01-12 23:24:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-12 23:28:12
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
};