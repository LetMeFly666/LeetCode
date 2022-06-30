/*
 * @Author: LetMeFly
 * @Date: 2022-06-30 22:06:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-30 22:16:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

const ll mod = 1e9 + 7;

class Solution {
private:
    inline bool isPrime(int n) {
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    inline ll getK(int n) {
        if (n < 2)
            return 1;
        ll k = 1;
        while (n) {
            k = k * n-- % mod;
        }
        return k;
    }
public:
    int numPrimeArrangements(int n) {
        int prime = 0;
        for (int i = 2; i <= n; i++) {
            prime += isPrime(i);
        }
        // printf("prime: %d, not prime: %d\n", prime, n - prime);
        return getK(prime) * getK(n - prime) % mod;
    }
};