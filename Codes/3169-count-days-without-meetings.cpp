/*
 * @Author: LetMeFly
 * @Date: 2025-07-11 23:25:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-11 23:33:35
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0;
        int last = 0;
        for (vector<int> me : meetings) {
            // printf("last = %d, me = [%d, %d]\n", last, me[0], me[1]);
            if (me[0] > last + 1) {
                ans += me[0] - last - 1;
                // printf("ans += %d\n", me[0] - last - 1);
            }
            last = max(last, me[1]);
        }
        ans += days - last;
        return ans;
    }
};