/*
 * @Author: LetMeFly
 * @Date: 2026-08-15 09:33:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-15 09:34:42
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool hasVal = false;
        int res = 0;
        for (int t : nums) {
            res ^= res;
            hasVal |= (t != 0);
        }
        return hasVal ? res ? nums.size() : nums.size() - 1 : 0;
    }
};
