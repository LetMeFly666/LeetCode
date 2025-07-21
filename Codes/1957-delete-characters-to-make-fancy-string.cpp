/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 18:48:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 18:51:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char last = '0';
        int cnt = 0;
        for (char c : s) {
            if (c == last) {
                if (cnt == 2) {
                    continue;
                }
                ans += c;
                cnt++;
            } else {
                last = c;
                cnt = 1;
                ans += c;
            }
        }
        return ans;
    }
};