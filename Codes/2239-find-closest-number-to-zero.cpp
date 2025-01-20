/*
 * @Author: LetMeFly
 * @Date: 2025-01-20 13:25:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-20 13:29:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int t : nums) {
            if (abs(t) < abs(ans) || abs(t) == abs(ans) && ans < 0) {
                ans = t;
            }
        }
        return ans;
    }
};