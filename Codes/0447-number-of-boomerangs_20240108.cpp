/*
 * @Author: LetMeFly
 * @Date: 2024-01-08 18:58:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-08 19:11:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (vector<int>& p : points) {
            unordered_map<int, int> ma;
            for (vector<int>& q : points) {
                ma[(p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])]++;
            }
            for (auto [_, cnt] : ma) {
                ans += cnt * (cnt - 1);
            }
        }
        return ans;
    }
};