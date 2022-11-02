/*
 * @Author: LetMeFly
 * @Date: 2022-11-02 09:45:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-02 09:50:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int M = 0;
        vector<int> ans = {0, 0};
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                int power = 0;
                for (auto& tower : towers) {
                    auto distance = sqrt((tower[0] - i) * (tower[0] - i) + (tower[1] - j) * (tower[1] - j));
                    if (distance <= radius)
                        power += tower[2] / (1 + distance);
                }
                if (power > M) {
                    M = power;
                    ans = {i, j};
                }
                else if (power == M) {
                    ans = min(ans, {i, j});
                }
            }
        }
        return ans;
    }
};