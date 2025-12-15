/*
 * @Author: LetMeFly
 * @Date: 2025-12-14 17:30:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-14 17:37:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string& corridor) {
        ll ans = 1;
        int now = 0;
        bool ing = false;  // 正在处理两块座位之间的绿植
        bool atLeast2 = false;
        for (char c : corridor) {
            if (c == 'S') {
                if (ing) {
                    ans = ans * (now + 1) % MOD;
                    ing = false;
                    now = 1;
                } else {
                    now++;
                    if (now == 2) {
                        ing = true;
                        now = 0;
                        atLeast2 = true;
                    }
                }
            } else {  // 'P'
                if (ing) {
                    now++;
                }
            }
        }
        if (!ing || !atLeast2) {
            return 0;
        }
        return static_cast<int>(ans);
    }
};