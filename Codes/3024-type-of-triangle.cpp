/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:26:07
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] < nums[2]) {
            return "none";
        }
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
};