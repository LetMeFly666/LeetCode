/*
 * @Author: LetMeFly
 * @Date: 2026-08-06 15:20:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-06 15:21:51
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(int n, int t) {
        int mul = 1;
        while (n) {
            mul *= n % 10;
            n /= 10;
        }
        return mul % t == 0;
    }
public:
    int smallestNumber(int n, int t) {
        while (!ok(n, t)) {
            n++;
        }
        return n;
    }
};
