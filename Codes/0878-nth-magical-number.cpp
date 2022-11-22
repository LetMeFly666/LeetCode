/*
 * @Author: LetMeFly
 * @Date: 2022-11-22 10:31:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-22 10:37:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    int nthMagicalNumber(int n, ll a, ll b) {
        ll c = lcm(a, b);
        ll l = min(a, b), r = n * min(a, b);
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (mid / a + mid / b - mid / c >= n)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return (r + 1) % 1000000007;
    }
};