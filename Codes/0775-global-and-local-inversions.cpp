/*
 * @Author: LetMeFly
 * @Date: 2022-11-16 08:12:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-16 08:12:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int M = nums[0];
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (M > nums[i])
                return false;
            M = max(M, nums[i - 1]);
        }
        return true;
    }
};