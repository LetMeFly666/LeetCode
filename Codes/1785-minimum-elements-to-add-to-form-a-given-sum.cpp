/*
 * @Author: LetMeFly
 * @Date: 2022-12-16 19:09:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-16 19:10:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minElements(vector<int>& nums, int limit, long long goal) {
        for (int t : nums)
            goal -= t;
        goal = abs(goal);
        return goal / limit + (goal % limit != 0);
    }
};