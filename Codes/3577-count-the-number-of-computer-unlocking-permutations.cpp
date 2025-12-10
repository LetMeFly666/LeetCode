/*
 * @Author: LetMeFly
 * @Date: 2025-12-10 22:34:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-10 22:48:50
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini = 1000000001, miniTimes = 1;
        for (int t : complexity) {
            if (t < mini) {
                mini = t;
                miniTimes = 1;
            } else if (t == mini) {
                miniTimes++;
            }
        }
        // printf("mini: %d, miniTimes: %d\n", mini, miniTimes);
        if (miniTimes != 1) {
            return 0;
        }
        ll ans = 1;
        for (ll i = complexity.size() - 1; i > 1; i--) {
            ans = ans * i % MOD;
        }
        return static_cast<int>(ans);
    }
};