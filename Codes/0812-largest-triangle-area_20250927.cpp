/*
 * @Author: LetMeFly
 * @Date: 2025-09-27 12:53:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-27 15:10:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int calc(vector<vector<int>>& points, int i, int j, int k) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        int x3 = points[k][0], y3 = points[k][1];
        return abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    ans = max(ans, calc(points, i, j, k));
                }
            }
        }
        return double(ans) / 2;
    }
};