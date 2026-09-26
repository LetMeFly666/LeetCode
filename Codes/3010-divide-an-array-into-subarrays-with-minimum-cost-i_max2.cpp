/*
 * @Author: LetMeFly
 * @Date: 2026-02-01 09:49:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-01 09:56:48
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = 100, min2 = 100;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};