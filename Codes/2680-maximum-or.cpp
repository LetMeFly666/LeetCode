/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:09:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 15:17:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll maximumOr(vector<int>& nums, int k) {
        vector<int> suffix(nums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }
        ll ans = 0;
        int prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, (ll)(nums[i]) << k | prefix | suffix[i + 1]);
            prefix |= nums[i];
        }
        return ans;
    }
};