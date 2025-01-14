/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 17:04:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 17:05:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 24; i++) {
            int cnt = 0;
            for (int t : candidates) {
                cnt += t >> i & 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};