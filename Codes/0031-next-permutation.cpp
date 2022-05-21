/*
 * @Author: LetMeFly
 * @Date: 2022-05-16 10:25:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-16 10:25:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};