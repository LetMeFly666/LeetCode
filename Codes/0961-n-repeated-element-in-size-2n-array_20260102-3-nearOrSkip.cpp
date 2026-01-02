/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 13:21:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 13:29:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) {
                return nums[i];
            }
        }
        return nums[0];  // 前面循环中未判断nums[0]是否等于nums[1]，若前面未return则说明nums[0]=nums[1]如[1, 1, 2, 3]
    }
};