/*
 * @Author: LetMeFly
 * @Date: 2026-07-23 14:50:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-23 15:59:42
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unsigned n = nums.size();
        return n < 3 ? n : 1 << bit_width(n);
    }
};
