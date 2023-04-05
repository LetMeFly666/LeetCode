/*
 * @Author: LetMeFly
 * @Date: 2023-04-05 12:45:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-05 12:52:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一，枚举到min(a, b)
class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                ans++;
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 方法二，枚举到sqrt(gcd(a, b))
class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int c = gcd(a, b);
        int to = sqrt(c);
        for (int i = 1; i <= to; i++) {
            if (c % i == 0) {
                ans++;
                if (c / i != i) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry