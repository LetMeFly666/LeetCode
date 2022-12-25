/*
 * @Author: LetMeFly
 * @Date: 2022-12-25 15:30:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-25 17:23:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
typedef long long ll;
class Solution {
public:
    int minimumBoxes(ll n) {
        ll buttom = 1, nextAdd = 2;
        ll total = 1;
        ll ans = n;
        while (total <= n) {
            ans = min(ans, buttom + (n - total));
            buttom += nextAdd, nextAdd++;
            total += buttom;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
typedef long long ll;
class Solution {
public:
    int minimumBoxes(ll n) {
        ll bottom = 1, nextAdd = 2;
        ll total = 1;
        ll lastBottom, lastTotal;
        while (total <= n) {
            lastBottom = bottom, lastTotal = total;
            bottom += nextAdd, nextAdd++;
            total += bottom;
        }
        total = lastTotal, bottom = lastBottom;
        // printf("bottom = %d, total = %d\n", bottom, total);  //**********
        ll ans = bottom;
        for (int i = 1; total < n; i++) {
            ans++;
            total += i;
        }
        return ans;
    }
};
#endif  // FirstTry