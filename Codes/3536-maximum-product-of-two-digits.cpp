/*
 * @Author: LetMeFly
 * @Date: 2026-07-25 22:11:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-25 22:11:39
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        while (n) {
            int t = n % 10;
            n /= 10;
            if (t > mx2) {
                mx1 = mx2;
                mx2 = t;
            } else if (t > mx1) {
                mx1 = t;
            }
        }
        return mx1 * mx2;
    }
};
