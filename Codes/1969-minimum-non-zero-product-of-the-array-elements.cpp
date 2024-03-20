/*
 * @Author: LetMeFly
 * @Date: 2024-03-20 10:42:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-20 11:01:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error，快速幂写错了
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
private:
    ll Pow(ll a, ll b) {
        ll ans = 1;
        ll k = 1;
        while (b) {
            if (b & 1) {
                k = (k * a) % MOD;
            }
            b >>= 1;
            ans = (ans * k) % MOD;
        }
        return ans;
    }
public:
    // (2 ^ p - 1) * ((2 ^ p - 2) ^ ((2 ^ p - 2) / 2))
    int minNonZeroProduct(int p) {
        return ((1LL << p) - 1) * Pow((1LL << p) - 2, ((1LL << p) - 2) / 2);
    }
};
#else  // FirstTry
// SecondTry
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
private:
    ll Pow(ll a, ll b) {
        a %= MOD;
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    // (2 ^ p - 1) * ((2 ^ p - 2) ^ ((2 ^ p - 2) / 2))
    int minNonZeroProduct(int p) {
        return (((1LL << p) - 1) % MOD) * Pow((1LL << p) - 2, ((1LL << p) - 2) / 2) % MOD;
    }
};
#endif  // FirstTry