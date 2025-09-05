/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 23:51:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 23:53:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
nums1 - k * nums2 = 2^{i_1} + 2^{i_2} + ... + 2^{i_k}
*/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (1 <= num1 - num2) {
            return -1;
        }
        int k = 1;
        while (k++) {
            if (k >= __builtin_popcountll(num1 - (long long)num2 * k)) {
                return k;
            }
        }
        return -2;  // Fake Return: unreachable
    }
};