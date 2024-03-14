/*
 * @Author: LetMeFly
 * @Date: 2024-03-14 08:51:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-14 08:54:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxArrayValue(vector<int>& nums) {
        ll ans = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= ans) {
                ans += nums[i];
            }
            else {
                ans = nums[i];
            }
        }
        return ans;
    }
};