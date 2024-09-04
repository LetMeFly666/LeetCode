/*
 * @Author: LetMeFly
 * @Date: 2024-09-03 18:23:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-03 18:28:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

// 9^{13} = 2541865828329
class Solution {
public:
    ll maxStrength(vector<int>& nums) {
        ll m = nums[0], M = m;
        for (int i = 1; i < nums.size(); i++) {
            ll newm = min({m, (ll)nums[i], m * nums[i], M * nums[i]});
            ll newM = max({M, (ll)nums[i], m * nums[i], M * nums[i]});
            m = newm, M = newM;
        }
        return M;
    }
};