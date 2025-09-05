/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 09:55:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 10:04:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            int mxY = -1;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][1] > mxY && points[j][1] <= points[i][1]) {
                    ans++;
                    mxY = points[j][1];
                }
            }
        }
        return ans;
    }
};