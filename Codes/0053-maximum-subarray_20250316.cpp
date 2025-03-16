/*
 * @Author: LetMeFly
 * @Date: 2025-03-16 10:32:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-16 10:35:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int M = nums[0];
        for (int t : nums) {
            M = max(M, t);
            cnt = max(cnt + t, 0);
            ans = max(ans, cnt);
        }
        return M >= 0 ? ans : M;
    }
};