/*
 * @Author: LetMeFly
 * @Date: 2025-12-10 22:34:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-10 22:45:08
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
        if (miniTimes != 1) {
            return 0;
        }
        int n = complexity.size() - 1;
        return static_cast<int>(static_cast<ll>(n) * static_cast<ll>(n - 1) % MOD);
    }
};