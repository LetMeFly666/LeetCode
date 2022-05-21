/*
 * @Author: LetMeFly
 * @Date: 2022-04-11 08:53:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-11 09:11:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// WA
int C(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    return C(a - 1, b - 1) + C(a - 1, b);
}

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int cnt = 10;
        if (n == 1)
            return cnt;
        for (int i = 2; i <= n; i++) {
            cnt += C(10, i);
            cnt -= C(9, i - 1);
        }
        return cnt;
    }
};
#else
// LeetCode
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int ans = 10, cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur *= 9 - i;
            ans += cur;
        }
        return ans;
    }
};
#endif

#ifdef _WIN32
int main() {
    int a, b;
    while (cin >> a >> b)
        cout << C(a, b) << endl;
    return 0;
}
#endif