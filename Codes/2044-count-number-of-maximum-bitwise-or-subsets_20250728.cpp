/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 13:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 18:51:34
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxium = 0;
        for (int t : nums) {
            maxium |= t;
        }
        int ans = 0;
        int n = nums.size(), mask = 1 << n;
        for (int i = 0; i < mask; i++) {
            int thisVal = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    thisVal |= nums[j];
                }
            }
            ans += thisVal == maxium;
        }
        return ans;
    }
};