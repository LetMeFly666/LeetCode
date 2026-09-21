/*
 * @Author: LetMeFly
 * @Date: 2026-09-21 10:32:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-21 10:49:56
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    vector<ll> resultArray(vector<int>& nums, int k) {
        ll dp[k] = {0};
        for (int t : nums) {
            t %= k;
            ll dp2[k] = {0};
            
            swap(dp, dp2);
        }
        return vector<ll>(dp, dp + k);
    }
};
