/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 23:51:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-06 00:13:36
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// **** 这段代码不能通过这道题，但是它的错误样例能帮你更好地理解正确代码

/*
nums1 - k * nums2 = 2^{i_1} + 2^{i_2} + ... + 2^{i_k}
*/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 - num2 < 1) {
            return -1;
        }
        int k = 0;
        while (++k) {
            if (k >= __builtin_popcountll(num1 - (long long)num2 * k)) {
                return k;
            }
        }
        return -2;  // Fake Return: unreachable
    }
};

// 这样写的错因在于没有限制上界
// 16 10会在k=2时不满足上界而退出