/*
 * @Author: LetMeFly
 * @Date: 2025-12-10 22:34:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-10 22:56:22
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        ll ans = 1;
        for (ll i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = ans * i % MOD;
        }
        return static_cast<int>(ans);
    }
};