/*
 * @Author: LetMeFly
 * @Date: 2023-06-05 12:41:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-05 12:49:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int loc = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[loc++] = nums[i];
            }
        }
        while (loc < nums.size()) {
            nums[loc++] = 0;
        }
        return nums;
    }
};