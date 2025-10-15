/*
 * @Author: LetMeFly
 * @Date: 2025-10-15 22:07:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-15 22:16:10
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 1;
        int lastVal = 1000000001, lastCnt = 0, nowCnt = 0;
        for (int t : nums) {
            if (t <= lastVal) {
                ans = max(ans, min(lastCnt, nowCnt));
                ans = max(ans, nowCnt / 2);
                printf("ans = %d, t = %d, lastCnt = %d, nowCnt = %d\n", ans, t, lastCnt, nowCnt);
                lastCnt = nowCnt, nowCnt = 1;
            } else {
                nowCnt++;
            }
            lastVal = t;
        }
        return max({ans, min(lastCnt, nowCnt), nowCnt / 2});
    }
};
