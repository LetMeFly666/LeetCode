/*
 * @Author: LetMeFly
 * @Date: 2024-04-09 11:51:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-09 11:53:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntPos = 0, cntNeg = 0;
        for (int t : nums) {
            cntPos += t > 0;
            cntNeg += t < 0;
        }
        return max(cntPos, cntNeg);
    }
};