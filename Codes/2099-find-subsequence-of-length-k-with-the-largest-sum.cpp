/*
 * @Author: LetMeFly
 * @Date: 2025-07-03 21:31:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-03 21:34:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int M = 0, l = 0, r = k - 1;
        for (int i = 0; i < k; i++) {
            M += nums[i];
        }
        for (int i = 1; i + k - 1 < nums.size(); i++) {
            int now = M + nums[i + k - 1] - nums[i];
            if (now > M) {
                M = now;
                l = i;
                r = i + k - 1;
            }
        }
        return vector<int>(nums.begin() + i, nums.begin() + i + k - 1);
    }
};