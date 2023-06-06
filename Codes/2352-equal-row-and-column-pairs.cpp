/*
 * @Author: LetMeFly
 * @Date: 2023-06-06 10:08:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-06 10:11:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef unsigned long long ull;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<ull, int> ma;
        for (int i = 0; i < n; i++) {
            ull hash_ = 0;
            for (int j = 0; j < n; j++) {
                hash_ = hash_ * 131 + grid[i][j];
            }
            ma[hash_]++;
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            ull hash_ = 0;
            for (int i = 0; i < n; i++) {
                hash_ = hash_ * 131 + grid[i][j];
            }
            ans += ma[hash_];
        }
        return ans;
    }
};