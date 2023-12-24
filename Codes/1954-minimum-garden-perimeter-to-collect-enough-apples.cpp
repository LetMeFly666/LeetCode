/*
 * @Author: LetMeFly
 * @Date: 2023-12-24 16:23:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-24 16:37:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
x: 2(2n+1)(1+2+...+n)=n(n+1)(2n+1)
y = x
x + y: 2n(n+1)(2n+1) = 4n(n+1)(n+0.5)≈4n^3
*/
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long ans = cbrt((double)0.25 * neededApples);
        while (2 * ans * (ans + 1) * (2 * ans + 1) <  neededApples) {
            ans++;
        }
        return ans * 8;
    }
};