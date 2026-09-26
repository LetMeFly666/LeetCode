/*
 * @Author: LetMeFly
 * @Date: 2026-06-19 10:15:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-19 10:16:25
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, now = 0;
        for (int t : gain) {
            now += t;
            ans = max(ans, now);
        }
        return ans;
    }
};
