/*
 * @Author: LetMeFly
 * @Date: 2022-08-14 13:02:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-14 13:10:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << (31 - i)))
                ans |= (1 << i);
        }
        return ans;
    }
};