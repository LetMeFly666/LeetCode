/*
 * @Author: LetMeFly
 * @Date: 2024-10-16 23:04:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-16 23:07:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1000;
        for (int i = 0; i < nums.size() / 2; i++) {
            ans = min(ans, nums[i] + nums[nums.size() - i - 1]);
        }
        return 1. * ans / 2;
    }
};