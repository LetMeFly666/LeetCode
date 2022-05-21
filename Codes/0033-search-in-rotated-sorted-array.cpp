/*
 * @Author: LetMeFly
 * @Date: 2022-04-18 11:45:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-18 14:59:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i])
                return i;
        }
        return -1;
    }
};