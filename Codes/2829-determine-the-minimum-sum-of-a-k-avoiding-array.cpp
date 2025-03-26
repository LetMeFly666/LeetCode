/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:08:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:18:27
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
        int firstCanChooseTo = min(n, max(2, (k - 1) / 2));
        int ans = firstCanChooseTo * (firstCanChooseTo + 1) / 2;
        n -= firstCanChooseTo;
        if (n) {
            ans += n * (k + k + n - 1) / 2;  // k, k+1, k+2, ... 共n个
        }
        return ans;
    }
};