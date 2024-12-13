/*
 * @Author: LetMeFly
 * @Date: 2024-12-13 09:32:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-13 09:33:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int m = nums[0], loc = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < m) {
                    m = nums[i];
                    loc = i;
                }
            }
            nums[loc] *= multiplier;
        }
        return nums;
    }
};