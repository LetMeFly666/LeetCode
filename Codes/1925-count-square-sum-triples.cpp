/*
 * @Author: LetMeFly
 * @Date: 2025-12-08 18:40:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-08 18:42:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int k = a * a + b * b;
                int c = sqrt(k);
                ans += c * c == k;
            }
        }
        return ans;
    }
};