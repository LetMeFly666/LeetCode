/*
 * @Author: LetMeFly
 * @Date: 2025-01-06 20:32:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-06 20:35:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = top - special.back();
        bottom--;
        for (int t : special) {
            ans = max(ans, t - bottom - 1);
            bottom = t;
        }
        return ans;
    }
};