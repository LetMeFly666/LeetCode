/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:29:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 15:32:32
 * @Descriptions: Fake Time
 * @Descriptions: AC,100.00%,90.30%
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll maximumOr(vector<int>& nums, int k) {
        int allOr = 0, all1 = 0;
        for (int t : nums) {
            all1 |= allOr & t;
            allOr |= t;
        }
        ll ans = 0;
        for (int t : nums) {
            ans = max(ans, allOr ^ t | all1 | (ll)(t) << k);
        }
        return ans;
    }
};