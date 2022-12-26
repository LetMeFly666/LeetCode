/*
 * @Author: LetMeFly
 * @Date: 2022-12-26 15:47:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-26 15:58:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 以为是2^n-1  // Error
typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
private:
    ll Pow(int n) {  // 2^n
        ll ans = 1, two = 2;
        while (n) {
            if (n & 1) {
                ans = ans * two % mod;
            }
            two = two * two % mod;
            n >>= 1;
        }
        return ans;
    }
public:
    int countHomogenous(string s) {
        ll ans = 0;
        char lastChar = s[0];
        int cnt = 0;
        for (char c : s) {
            if (c != lastChar) {
                ans = (ans + Pow(cnt) - 1) % mod;
                printf("ans = %lld\n", ans);  //**********
                cnt = 1, lastChar = c;
            }
            else {
                cnt++;
            }
        }
        ans = (ans + Pow(cnt) - 1) % mod;
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // n(n+1)/2
typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
    int countHomogenous(string s) {
        ll ans = 0;
        char lastChar = s[0];
        ll cnt = 0;
        for (char c : s) {
            if (c != lastChar) {
                ans = (ans + cnt * (cnt + 1) / 2) % mod;
                printf("ans = %lld\n", ans);  //**********
                cnt = 1, lastChar = c;
            }
            else {
                cnt++;
            }
        }
        ans = (ans + cnt * (cnt + 1) / 2) % mod;
        return ans;
    }
};
#endif  // FirstTry