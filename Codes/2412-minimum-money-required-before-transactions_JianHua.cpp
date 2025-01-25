/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 09:58:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 09:59:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll minimumMoney(vector<vector<int>>& transactions) {
        ll ans = 0;
        int M = 0;
        for (vector<int>& t : transactions) {
            ans += max(0, t[0] - t[1]);
            M = max(M, min(t[0], t[1]));
        }
        return ans + M;
    }
};