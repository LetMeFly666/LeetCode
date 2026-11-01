/*
 * @Author: LetMeFly
 * @Date: 2026-11-01 10:57:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-01 10:58:17
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = nums[0];
        for (int t : nums) {
            m = min(m, t);
        }
        int ans = 0;
        for (int t : nums) {
            ans += t - m;
        }
        return ans;
    }
};
