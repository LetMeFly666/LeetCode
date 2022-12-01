/*
 * @Author: LetMeFly
 * @Date: 2022-12-01 14:02:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-01 14:05:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int m = 1e5, ans = -1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int d = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (d < m) {
                    m = d, ans = i;
                }
            }
        }
        return ans;
    }
};