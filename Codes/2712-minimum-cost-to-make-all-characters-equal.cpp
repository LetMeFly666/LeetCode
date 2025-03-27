/*
 * @Author: LetMeFly
 * @Date: 2025-03-27 11:26:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-27 21:52:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
/*
010101
110101
000101
000100
000111
000000
*/
class Solution {
public:
    ll minimumCost(string s) {
        ll ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans += min(i, n - i);
            }
        }
        return ans;
    }
};