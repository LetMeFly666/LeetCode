/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:08:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:31:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
5 4
1 2 4 5 6

2 6
1 2

7 7
1 2 3 7 8 9 10

7 8
1 2 3 8 9 10 11

3 4
1 2 4

6 6
1 2 6 7

奇数：1, 2, k/2, k, k+1, k+2, ...
偶数：1, 2一定可选, 最多选到k/2-1，  然后开始k, k+1, k+2

Arnhem
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int to;
        if (k % 2) {
            to = min(n, k / 2);
        } else {
            if (k == 2) {
                to = 1;
            } else if (k == 4) {
                to = 2;
            } else {
                to = k / 2 - 1;
            }
        }
        int ans = to * (1 + to) / 2;
        n -= to;
        ans += n * (k + k + n - 1) / 2;
        return ans;
    }
};