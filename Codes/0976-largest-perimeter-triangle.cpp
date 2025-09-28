/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:22:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};