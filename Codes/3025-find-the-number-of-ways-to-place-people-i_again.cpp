/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 13:08:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 13:51:14
 * @Description: rewrite from 0
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool check(vector<vector<int>>& points, int i, int j) {
        return i != j && points[i][0] <= points[j][0] && points[i][1] >= points[j][1];
    }

    inline bool check(vector<vector<int>>& points, int i, int j, int k) {
        return !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0]
              && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]);
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (!check(points, i, j)) {
                    continue;
                }
                bool can = true;
                for (int k = 0; k < points.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (!check(points, i, j, k)) {
                        can = false;
                        break;
                    }
                }
                ans += can;
            }
        }
        return ans;
    }
};
    