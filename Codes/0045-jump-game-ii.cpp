/*
 * @Author: LetMeFly
 * @Date: 2025-01-27 07:44:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-27 07:47:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, nowMax = 0, nextMax = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            nextMax = max(nextMax, i + nums[i]);
            if (nowMax == i) {
                ans++;
                nowMax = nextMax;
            }
        }
        return ans;
    }
};