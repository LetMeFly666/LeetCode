/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:08:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:43:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
5 4
1 2 4 5 6

2 6
1 2

∞ 1
1

∞ 2
1 2

∞ 3
1 3

∞ 4
1 2

∞ 5
1 2

∞ 6
1 2 3

∞ 7
1 2 3

∞ 8
1 2 3 4

∞ 9
1 2 3 4

小于k的数最多从1加到k/2(下取整)
之后就可以从k开始k, k+1, k+2, ...了
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int to = min(n, k / 2);
        int ans = to * (to + 1) / 2;
        n -= to;
        ans += n * (k + k + n - 1) / 2;
        return ans;
    }
};