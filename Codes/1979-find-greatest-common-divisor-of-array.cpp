/*
 * @Author: LetMeFly
 * @Date: 2026-07-18 07:00:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-18 07:01:47
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = nums[0], M = m;
        for (int t : nums) {
            m = min(m, t);
            M = max(M, t);
        }
        return gcd(m, M);
    }
};
