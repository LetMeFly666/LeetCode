/*
 * @Author: LetMeFly
 * @Date: 2023-10-10 11:47:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-10 14:10:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] += (s[i] == 'L' ? -1 : 1) * d;
        }
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for (ll i = 1; i < n; i++) {
            ans = (ans + (i * (n - i) % MOD) * ((ll)nums[i] - nums[i - 1])) % MOD;
        }
        return ans;
    }
};