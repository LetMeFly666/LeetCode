/*
 * @Author: LetMeFly
 * @Date: 2024-06-14 16:40:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-14 16:45:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxScore(vector<int>& nums, int x) {
        ll odd = nums[0] % 2 ? 0 : -x, even = nums[0] % 2 ? -x : 0;
        for (int t : nums) {
            if (t % 2) {
                odd = max(odd + t, even + t - x);
            }
            else {
                even = max(odd + t - x, even + t);
            }
        }
        return max(odd, even);
    }
};