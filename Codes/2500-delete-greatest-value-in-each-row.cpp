/*
 * @Author: LetMeFly
 * @Date: 2023-07-27 08:28:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-27 08:28:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (vector<int>& v : grid) {
            sort(v.begin(), v.end());
        }
        int ans = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            int thisValue = grid[0][j];
            for (int i = 1; i < grid.size(); i++) {
                thisValue = max(thisValue, grid[i][j]);
            }
            ans += thisValue;
        }
        return ans;
    }
};