/*
 * @Author: LetMeFly
 * @Date: 2025-02-20 11:04:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-20 11:06:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        bool index = false;
        while (n) {
            ans[index] += n & 1;
            index = !index;
            n >>= 1;
        }
        return ans;
    }
};