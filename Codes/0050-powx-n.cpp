/*
 * @Author: LetMeFly
 * @Date: 2022-05-25 13:26:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-25 13:43:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    double Pow(double x, long long n) {  // -INT_MIN > INT_MAX
        double ans = 1;
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x = x * x;
            #ifdef _WIN32
            dbg(n);
            #endif
            n >>= 1;
        }
        return ans;
    }
public:
    double myPow(double x, long long n) {
        return n > 0 ? Pow(x, n) : 1 / Pow(x, -n);
    }
};

#ifdef _WIN32
int main() {
    double x;
    ll n;
    while (cin >> x >> n) {
        Solution sol;
        cout << sol.myPow(x, n) << endl;
    }
    return 0;
}
#endif