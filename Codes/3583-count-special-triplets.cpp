/*
 * @Author: LetMeFly
 * @Date: 2025-12-09 18:38:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-09 18:41:50
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const long long MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        ll ans = 0;
        unordered_map<int, int> total, now;
        for (int t : nums) {
            total[t]++;
        }
        for (int t : nums) {
            int finding = t * 2;
            if (now.count(finding)) {
                ll left = now[finding];
                ans = (ans + left * (total[finding] - left)) % MOD;
            }
            now[t]++;
        }
        return ans;
    }
};