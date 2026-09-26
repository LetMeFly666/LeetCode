/*
 * @Author: LetMeFly
 * @Date: 2026-07-16 16:46:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-16 16:50:00
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll gcdSum(vector<int>& nums) {
        int mx = 0;
        for (int& t : nums) {
            mx = max(mx, t);
            t = gcd(mx, t);
        }
        ranges::sort(nums);

        ll ans = 0;
        for (int i = 0, n = nums.size(); i < n / 2; i++) {
            ans += gcd(nums[i], nums[n - i - 1]);
        }
        return ans;
    }
};
