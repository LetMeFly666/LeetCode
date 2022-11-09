/*
 * @Author: LetMeFly
 * @Date: 2022-10-21 21:15:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-21 21:22:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            int rightMost = points[i][1];
            while (i + 1 < points.size() && points[i + 1][0] <= rightMost) {
                rightMost = min(rightMost, points[++i][1]);
            }
            ans++;
        }
        return ans;
    }
};