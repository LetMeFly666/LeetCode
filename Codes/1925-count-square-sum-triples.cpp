/*
 * @Author: LetMeFly
 * @Date: 2025-12-08 18:40:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-08 18:47:09
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int k = a * a + b * b;
                int c = sqrt(k);
                ans += c * c == k && c <= n;
                // if (c * c == k) {
                //     printf("(%d, %d, %d)\n", a, b, c);
                // }
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
int main() {
    Solution sol;
    cout << sol.countTriples(5) << endl;
    cout << sol.countTriples(12) << endl;
    return 0;
}
#endif