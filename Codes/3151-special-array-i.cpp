/*
 * @Author: LetMeFly
 * @Date: 2024-08-13 23:51:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-13 23:51:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};