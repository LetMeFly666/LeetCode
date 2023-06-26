/*
 * @Author: LetMeFly
 * @Date: 2023-06-26 09:34:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-26 09:39:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
1 + 2 + 3 + ... + x = x + (x + 1) + ... + n

x * (x + 1) / 2 = (n - x + 1) * (x + n) / 2

x * (x + 1) = (n - x + 1) * (x + n)

x^2 + x = nx - x^2 + x + n^2 - nx + n

2x^2 = n^2 + n

x = sqrt((n^2 + n) / 2)

n^2 + n = n(n + 1)一定是偶数，能整除2

就看n^2 + n是不是平方数了
*/

class Solution {
public:
    int pivotInteger(int n) {
        int ans = sqrt((n * n + n) / 2);
        return ans * ans == (n * n + n) / 2 ? ans : -1;
    }
};