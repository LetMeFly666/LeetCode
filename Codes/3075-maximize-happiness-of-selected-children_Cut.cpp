/*
 * @Author: LetMeFly
 * @Date: 2025-12-25 12:59:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-25 13:00:12
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            happiness[i] -= i;
            if (happiness[i] <= 0) {
                return ans;
            }
            ans += happiness[i];
        }
        return ans;
    }
};