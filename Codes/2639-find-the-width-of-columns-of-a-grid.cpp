/*
 * @Author: LetMeFly
 * @Date: 2024-04-27 11:04:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-27 11:06:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for (int j = 0; j < grid[0].size(); j++) {
            int thisAns = 1;
            for (int i = 0; i < grid.size(); i++) {
                thisAns = max(thisAns, (int)to_string(grid[i][j]).size());
            }
            ans[j] = thisAns;
        }
        return ans;
    }
};