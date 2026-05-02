/*
 * @Author: LetMeFly
 * @Date: 2026-05-02 19:10:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-02 19:12:08
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static const int mask = (1 << 2) | (1 << 5) | (1 << 6) | (1 << 9);

    int ok(int n) {
        while (n) {
            if (!((1 << (n % 10)) & mask)) {
                return 0;
            }
            n /= 10;
        }
        return 1;
    }
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += ok(i);
        }
        return ans;
    }
};
