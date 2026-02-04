/*
 * @Author: LetMeFly
 * @Date: 2026-02-04 21:46:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-04 21:49:42
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool state = 0;
        if (nums[1] <= nums[0]) {
            return false;
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            if (state == 0) {
                if (nums[i] < nums[i - 1]) {
                    state = 1;
                }
            } else if (state == 1) {
                if (nums[i] > nums[i - 1]) {
                    state = 2;
                }
            } else if (state == 3) {
                if (nums[i] < nums[i - 1]) {
                    return false;
                }
            }
        }
        return state == 3;
    }
};