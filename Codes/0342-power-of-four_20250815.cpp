/*
 * @Author: LetMeFly
 * @Date: 2025-08-15 18:29:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-15 18:40:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isPowerOfFour(int n) {
        int k = sqrt(n);
        return n > 0 && k * k == n && (n & (n - 1)) == n;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
16

*/
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.isPowerOfFour(n) << endl;
    }
    return 0;
}
#endif