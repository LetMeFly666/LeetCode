/*
 * @Author: LetMeFly
 * @Date: 2024-01-08 18:58:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-08 19:04:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> ma;  // [dis^2, cnt]
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                ma[(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])]++;
            }
        }
        int ans = 0;
        for (auto [_, cnt] : ma) {
            ans += cnt * (cnt - 1);
        }
        return ans;
    }
};