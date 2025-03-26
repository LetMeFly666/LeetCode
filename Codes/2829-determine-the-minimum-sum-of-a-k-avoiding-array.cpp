/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:08:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:32:55
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

3 6
1 2 6 -> 9

实际上可以  1, 2, 3

啊这！读题读错了

是元素对的和不能为k，而不是任意子数组的和不能为k
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int to;
        if (k % 2) {
            to = k / 2;
        } else {
            if (k == 2) {
                to = 1;
            } else if (k == 4) {
                to = 2;
            } else {
                to = k / 2 - 1;
            }
        }
        to = min(to, n);
        int ans = to * (1 + to) / 2;
        n -= to;
        ans += n * (k + k + n - 1) / 2;
        return ans;
    }
};