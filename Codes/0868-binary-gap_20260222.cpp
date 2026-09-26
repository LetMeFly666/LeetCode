/*
 * @Author: LetMeFly
 * @Date: 2026-02-22 09:59:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-22 10:04:00
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int binaryGap(int n) {
        n /= (n & -n) * 2;
        int ans = 0, cnt = 1;
        while (n) {
            if (n & 1) {
                ans = max(ans, cnt);
                cnt = 0;
            }
            cnt++;
            n >>= 1;  // Don't forget
        }
        return ans;
    }
};