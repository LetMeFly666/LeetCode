/*
 * @Author: LetMeFly
 * @Date: 2026-10-13 22:11:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-13 22:16:50
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
        ranges::sort(nums);

        ll ans = 0;
        int half = (nums.size() + 1) / 2;
        for (int i = 0; i < half; i++) {
            ans = ans + nums[i] * nums[i];
        }
        for (int i = half; i < nums.size(); i++) {
            ans = ans - nums[i] * nums[i];
        }
        return ans;
    }
};
