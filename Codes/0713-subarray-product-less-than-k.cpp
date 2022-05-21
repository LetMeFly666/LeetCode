/*
 * @Author: LetMeFly
 * @Date: 2022-05-05 08:42:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-05 08:49:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, mul = 1;
        for (int r = 0; r < nums.size(); r++) {
            mul *= nums[r];
            while (l <= r && mul >= k) {
                mul /= nums[l++];
            }
            ans += r - l + 1;
        }
        return ans;
    }
};