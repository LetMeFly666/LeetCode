/*
 * @Author: LetMeFly
 * @Date: 2025-01-28 10:03:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-28 10:05:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> all;
        all.push_back({1});
        for (int i = 1; i <= rowIndex; i++) {
            all.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                all[i][j] = all[i - 1][j - 1] + all[i - 1][j];
            }
        }
        return all.back();
    }
};