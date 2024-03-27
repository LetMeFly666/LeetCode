/*
 * @Author: LetMeFly
 * @Date: 2024-03-27 13:05:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-27 13:11:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int MOD = 1e9 + 7;
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int lastTo = -1;
        int ans = 1;
        for (vector<int>& range : ranges) {
            if (range[0] > lastTo) {
                ans = ans * 2 % MOD;
            }
            lastTo = max(lastTo, range[1]);
        }
        return ans;
    }
};