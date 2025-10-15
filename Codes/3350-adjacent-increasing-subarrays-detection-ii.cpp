/*
 * @Author: LetMeFly
 * @Date: 2025-10-15 22:07:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-15 22:12:42
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS IS NOT RIGHT
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 1;
        int lastVal = 1000000001, lastCnt = 0, nowCnt = 0;
        for (int t : nums) {
            if (t <= lastVal) {
                ans = max(ans, min(lastCnt, nowCnt));
                ans = max(ans, nowCnt / 2);
                lastCnt = nowCnt, nowCnt = 0;
            } else {
                nowCnt++;
            }
            lastVal = t;
        }
        return ans;
    }
};