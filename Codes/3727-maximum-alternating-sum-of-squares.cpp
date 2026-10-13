/*
 * @Author: LetMeFly
 * @Date: 2026-10-13 22:11:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-13 22:14:08
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        for (int& t : nums) {
            t = abs(t);
        }

        ll ans = 0;
        for (int l = 0, r = nums.size() - 1; l <= r; l++, r--) {
            ans += (ll) (nums[r] * nums[r]);
            if (l == r) {
                break;
            }
            ans -= (ll) (nums[l] * nums[l]);
        }
        return ans;
    }
};
