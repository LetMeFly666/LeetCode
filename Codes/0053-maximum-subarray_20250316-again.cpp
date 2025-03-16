/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 10:37:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 10:37:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], cnt = 0;
        for (int t : nums) {
            cnt = max(cnt + t, t);
            ans = max(ans, cnt);
        }
        return ans;
    }
};