/*
 * @Author: LetMeFly
 * @Date: 2024-12-10 14:52:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-10 15:08:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const vector<vector<int>> canFrom = {
    {4, 6},  // 0可以来自4，6
    {6, 8},
    {7, 9},
    {4, 8},
    {3, 9, 0},
    {},
    {1, 7, 0},
    {2, 6},
    {1, 3},
    {2, 4}
};
const int mod = 1e9 + 7;

class Solution {
public:
    int knightDialer(int n) {
        int last[10], now[10];
        fill(last, last + 10, 1);
        for (int i = 2; i <= n; i++) {
            memset(now, 0, sizeof(now));
            for (int j = 0; j < 10; j++) {
                for (int from : canFrom[j]) {
                    now[j] = (now[j] + last[from]) % mod;
                }
            }
            memcpy(last, now, sizeof(now));
        }
        // return accumulate(last, last + 10, 0);  // WA，这里没取模
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (ans + last[i]) % mod;
        }
        return ans;
    }
};