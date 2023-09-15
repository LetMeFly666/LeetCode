/*
 * @Author: LetMeFly
 * @Date: 2023-09-15 09:19:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-15 09:21:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& ab : operations) {
            int change = gem[ab[0]] / 2;
            gem[ab[0]] -= change;
            gem[ab[1]] += change;
        }
        int m = 1e7, M = 0;
        for (int g : gem) {
            m = min(m, g);
            M = max(M, g);
        }
        return M - m;
    }
};