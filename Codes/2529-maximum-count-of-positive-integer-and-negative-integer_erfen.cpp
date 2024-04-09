/*
 * @Author: LetMeFly
 * @Date: 2024-04-09 12:09:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-09 15:14:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(neg, pos);
    }
};