/*
 * @Author: LetMeFly
 * @Date: 2026-07-23 14:50:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-23 14:56:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        return (n & (-n)) << 1;
    }
};
