/*
 * @Author: LetMeFly
 * @Date: 2024-05-31 15:58:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-31 16:30:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> times(grid.size() * grid.size() + 1);
        for (vector<int>& line : grid) {
            for (int t : line) {
                times[t]++;
            }
        }
        vector<int> ans(2);
        for (int i = 1; i < times.size(); i++) {
            if (times[i] == 2) {
                ans[0] = i;
            }
            else if (times[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
};