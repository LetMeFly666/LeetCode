/*
 * @Author: LetMeFly
 * @Date: 2025-06-09 10:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-09 10:15:25
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int now = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = now;
            if (now * 10 <= n) {
                now *= 10;
            } else {
                while (now % 10 == 9 || now == n) {
                    now /= 10;
                }
                now++;
            }
        }
        return ans;
    }
};