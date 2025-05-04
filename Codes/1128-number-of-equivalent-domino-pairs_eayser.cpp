/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 16:12:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 16:13:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int times[81] = {0} ;
        int ans = 0;
        for (vector<int>& d : dominoes) {
            ans += times[d[0] < d[1] ? (d[0] - 1) * 9 + d[1] - 1 : (d[1] - 1) * 9 + d[0] - 1]++;
        }
        return ans;
    }
};