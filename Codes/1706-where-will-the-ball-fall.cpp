/*
 * @Author: LetMeFly
 * @Date: 2022-02-24 10:00:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-24 10:28:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        for (int i = 0; i < grid[0].size(); i++) {
            int loc = i;
            bool could = true;
            for (int j = 0; j < grid.size(); j++) {
                if ((grid[j][loc] == 1 && (loc + 1 >= grid[0].size() || grid[j][loc + 1] == -1)) || (grid[j][loc] == -1 && (loc - 1 < 0 || grid[j][loc - 1] == 1))) {
                    could = false;
                    break;
                }
                else {
                    loc += grid[j][loc];
                }
            }
            ans[i] = (could ? loc : -1);
        }
        return ans;
    }
};