/*
 * @Author: LetMeFly
 * @Date: 2025-04-05 22:38:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-06 14:25:36
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 1 << nums.size(); i >= 0; i--) {
            int thisVal = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    thisVal ^= nums[j];
                }
            }
            ans += thisVal;
        }
        return ans;
    }
};