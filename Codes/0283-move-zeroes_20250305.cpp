/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 22:52:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 23:13:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int loc0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                swap(nums[i], nums[loc0++]);
            }
        }
    }
};