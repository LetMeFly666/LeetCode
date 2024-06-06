/*
 * @Author: LetMeFly
 * @Date: 2024-06-06 22:33:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-06 22:36:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
1010
1001
0101
0011
*/
typedef long long ll;
class Solution {
public:
    ll minimumSteps(string s) {
        ll ans = 0, times = 0;
        for (char c : s) {
            if (c == '1') {
                times++;
            }
            else {
                ans += times;
            }
        }
        return ans;
    }
};