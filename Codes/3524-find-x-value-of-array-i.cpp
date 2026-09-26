/*
 * @Author: LetMeFly
 * @Date: 2026-09-21 10:32:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-21 13:38:56
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
typedef array<ll, 5> Data;
class Solution {
public:
    vector<ll> resultArray(vector<int>& nums, int k) {
        Data dp{};
        vector<ll> ans(k);
        for (int t : nums) {
            t %= k;
            Data dp2{};
            for (int i = 0; i < k; i++) {
                dp2[i * t % k] += dp[i];
            }
            dp2[t]++;
            for (int i = 0; i < k; i++) {
                ans[i] += dp2[i];
            }
            swap(dp, dp2);
        }
        return ans;
    }
};

#ifdef _DEBUG
/*
[1,2,3,4,5]
3

[9,2,4]
*/
int main() {
    string s;
    int a;
    while (cin >> s >> a) {
        Solution sol;
        vector<int> v = stringToVector(s);
        debug(sol.resultArray(v, a));
    }
    return 0;
}
#endif
