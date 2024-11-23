/*
 * @Author: LetMeFly
 * @Date: 2024-11-22 20:51:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-22 21:22:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 在搞什么
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int x = sqrt(i), y = sqrt(x);
            if (x * x == i && y * y != x) {
                ans++;
            }
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // WA，3是质数但不是平方数
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        int from = sqrt(l), to = sqrt(r);
        if (from * from != l) {
            from++;
        }
        if (to * to != r) {
            to--;
        }
        for (int i = from; i <= to; i++) {
            int t = sqrt(i);
            ans -= t * t == i;
            // printf("i = %d, sqrt(%d) * sqrt(%d) = %d\n", i, i, i, sqrt(i) * sqrt(i));  //*****
            printf("i = %d, t = %d, %d * %d = %d\n", i, t, t, t, t * t);  //*****
        }
        return ans;
    }
};
/*
i = 2, t = 1, 1 * 1 = 1
i = 3, t = 1, 1 * 1 = 1
i = 4, t = 2, 2 * 2 = 4
*/
#else  // SecondTry
#ifdef ThirdTry  // WHAT!!!   有点不在状态今天
class Solution {
private:
    int isPrime(int n) {
        // if (n == 1) {
        //     return false;
        // }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        int from = sqrt(l), to = sqrt(r);
        if (from * from != l) {
            from++;
        }
        for (int i = from; i < to; i++) {
            ans -= isPrime(i);
            // printf("isPrime(%d) = %d\n", i, isPrime(i));
        }
        return ans;
    }
};
#else  // ThirdTry
// FourthTry  // Copy
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<int> v(n + 1);
        int res = r - l + 1;
        for (int i = 2; i <= n; i++) {
            if (v[i] == 0) {
                if (i * i >= l && i * i <= r) {
                    res--;
                }
                for (int j = i * 2; j <= n; j += i) {
                    v[j] = 1;
                }
            }
        }
        return res;
    }
};
#endif  // ThirdTry
#endif  // SecondTry
#endif  // FirstTry