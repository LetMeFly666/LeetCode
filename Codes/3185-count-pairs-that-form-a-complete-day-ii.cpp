/*
 * @Author: LetMeFly
 * @Date: 2024-10-23 18:21:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-23 22:52:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
0 0
1 23
2 22
...
11 13
12 12
*/
typedef long long ll;
class Solution {
public:
    ll countCompleteDayPairs(vector<int>& hours) {
        ll bin[24] = {0};
        for (int t : hours) {
            bin[t % 24]++;
        }
        ll ans = bin[0] * (bin[0] - 1) / 2 + bin[12] * (bin[12] - 1) / 2;
        for (int i = 1; i < 12; i++) {
            ans += bin[i] * bin[24 - i];
        }
        return ans;
    }
};