/*
 * @Author: LetMeFly
 * @Date: 2022-11-18 09:31:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-18 09:37:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int n = nums.size();
        vector<ll> Pow(n);
        Pow[0] = 1;
        for (int i = 1; i < n; i++)
            Pow[i] = (Pow[i - 1] * 2) % MOD;
        for (int i = 0; i < n; i++) {
            ans = (ans + (Pow[i] - Pow[n - i - 1]) * nums[i]) % MOD;
        }
        return (ans % MOD + MOD) % MOD;
    }
};