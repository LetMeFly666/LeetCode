/*
 * @Author: LetMeFly
 * @Date: 2025-03-05 22:52:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-05 22:54:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int l = 0, r = nums.size() - 1; l < r; l++) {
            while (r > l && !nums[r]) {
                r--;
            }
            if (!nums[l]) {
                nums[l] = nums[r];
                nums[r--] = 0;
            }
        }
    }
};