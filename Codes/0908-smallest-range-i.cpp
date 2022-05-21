/*
 * @Author: LetMeFly
 * @Date: 2022-04-30 13:36:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-30 13:44:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// Copy from LeetCode
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
    }
};