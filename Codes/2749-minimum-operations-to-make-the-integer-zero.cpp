/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 18:29:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 23:57:58
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
        for (int k = 1; k <= num1 - (long long)num2 * k; k++) {
            if (k >= __builtin_popcountll(num1 - (long long)num2 * k)) {
                return k;
            }
        }
        return -1;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
16 10

*/
int main() {
    int a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.makeTheIntegerZero(a, b) << endl;
    }
    return 0;
}
#endif