/*
 * @Author: LetMeFly
 * @Date: 2026-05-02 19:10:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-02 19:19:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static const int mask_diff = (1 << 2) | (1 << 5) | (1 << 6) | (1 << 9);
    static const int mask_ok = mask_diff | (1 << 0) | (1 << 1) | (1 << 8);

    bool ok(int n) {
        bool has_diff = false;
        while (n) {
            int t = n % 10;
            if (!((1 << t) & mask_ok)) {
                return 0;
            }
            if ((1 << t) & mask_diff) {
                has_diff = true;
            }
            n /= 10;
        }
        return has_diff;
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
