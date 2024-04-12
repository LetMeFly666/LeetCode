/*
 * @Author: LetMeFly
 * @Date: 2024-04-12 13:48:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-12 13:50:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][ans]) {
                ans = i;
            }
        }
        return ans;
    }
};