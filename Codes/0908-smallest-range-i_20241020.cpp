/*
 * @Author: LetMeFly
 * @Date: 2024-10-21 14:25:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-21 14:25:43
 */
// 昨日每日一题，昨日没来得及做先Copy了
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int M = *max_element(nums.begin(), nums.end());
        int m = * min_element(nums.begin(), nums.end());
        return max(0, M - m - 2 * k);
    }
};