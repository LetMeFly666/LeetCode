/*
 * @Author: LetMeFly
 * @Date: 2025-10-11 18:10:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-11 18:14:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        if (n == 1) {
            return power[0];
        }
        if (n == 2) {
            return max(power[0], power[1]);
        }
        vector<int> dp(3);
        
    }
};