/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:11:26
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool ok(int n) {
        while (n) {
            if (n % 10 == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (ok(i) && ok(n - i)) {
                return {n, n - i};
            }
        }
        return {};  // FAKE RETURN
    }
};