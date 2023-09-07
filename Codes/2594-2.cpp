/*
 * @Author: LetMeFly
 * @Date: 2023-09-07 15:09:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-07 15:15:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

using ll = long long;
class Solution {
private:
    bool check(vector<int>& ranks, int cars, ll t) {
        ll cnt = 0;
        for (auto r : ranks) {
            cars -= sqrt(t / r);
        }
        return cnt >= cars;
    };

public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1ll * ranks[0] * cars * cars;
        while (l < r) {
            ll m = l + r >> 1;
            if (check(ranks, cars, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
