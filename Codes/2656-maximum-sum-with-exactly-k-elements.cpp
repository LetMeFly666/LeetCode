/*
 * @Author: LetMeFly
 * @Date: 2023-11-15 20:30:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-15 20:33:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int M = nums[0];
        for (int t : nums) {
            M = max(M, t);
        }
        return k * (M + M + k - 1) / 2;
    }
};