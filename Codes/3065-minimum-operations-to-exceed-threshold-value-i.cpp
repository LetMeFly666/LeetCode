/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 12:30:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 12:30:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int t : nums) {
            ans += t < k;
        }
        return ans;
    }
};