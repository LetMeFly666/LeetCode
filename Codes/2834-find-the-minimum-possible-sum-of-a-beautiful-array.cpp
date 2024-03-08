/*
 * @Author: LetMeFly
 * @Date: 2024-03-08 16:03:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-08 16:10:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int MOD = 1e9 + 7;
class Solution {  // AC,14.77%,62.50%
private:
    inline long long cal(long long l, long long r) {
        return (l + r) * (r - l + 1) / 2;
    }
public:
    int minimumPossibleSum(int n, int target) {
        long long half = target / 2;
        if (n <= half) {
            return cal(1, n);
        }
        return (cal(1, half) + cal(target, target + n - half - 1)) % MOD;
    }
};