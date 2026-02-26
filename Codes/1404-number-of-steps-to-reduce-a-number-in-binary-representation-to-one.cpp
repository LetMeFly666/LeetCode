/*
 * @Author: LetMeFly
 * @Date: 2026-02-26 22:06:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-26 23:55:06
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
1101
1110
111
1000
100
10
1
*/
// TODO: 高精度模拟
class Solution {
public:
    int numSteps(string s) {
        int now = 0, ans = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            now += s[i] - '0';
            
        }
        return ans;
    }
};
