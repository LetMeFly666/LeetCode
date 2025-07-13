/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 21:44:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 22:03:24
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += endTime[i] - startTime[i];
        }
        int ans = 0;
        int n = startTime.size();
        for (int i = k; i <= n; i++) {
            int l = (i == k ? 0 : endTime[i - k - 1]) + cnt;
            int r = (i == n ? eventTime : startTime[i]);
            ans = max(ans, r - l);
            // printf("i = %d, l = %d, r = %d, cnt = %d, ans = %d\n", i, l, r, cnt, ans);
            if (i == n) {
                break;
            }
            cnt += endTime[i] - startTime[i];
            cnt -= endTime[i - k] - startTime[i - k];
        }
        return ans;
    }
};