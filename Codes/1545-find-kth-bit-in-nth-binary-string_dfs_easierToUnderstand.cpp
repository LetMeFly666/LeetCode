/*
 * @Author: LetMeFly
 * @Date: 2026-03-03 09:14:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-03 09:39:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
n1 = 1
n2 = 2 * n1 + 1
n3 = 2 * n2 + 1
...
求n的通项公式
n_k = 2^k - 1
*/
class Solution {
private:
    inline char invert(char c) {
        return c == '0' ? '1' : '0';
    }
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        int len = (1 << n) - 1;
        int half_len = len >> 1;
        if (k == half_len + 1) {
            return '1';
        } else if (k <= half_len) {
            return findKthBit(n - 1, k);
        } else {
            return invert(findKthBit(n - 1, len - k + 1));  // n = 2, k = 3 -> len = 3, half_len = 1, next_k = 1
        }
    }
};
