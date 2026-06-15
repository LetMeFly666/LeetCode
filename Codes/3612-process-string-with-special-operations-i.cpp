/*
 * @Author: LetMeFly
 * @Date: 2026-06-16 00:07:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-16 00:08:11
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c : s) {
            if (c == '#') {
                ans = ans + ans;
            } else if (c == '%') {
                reverse(ans.begin(), ans.end());
            } else if (c == '*') {
                if (ans.size()) {
                    ans.pop_back();
                }
            } else {
                ans += c;
            }
        }
        return ans;
    }
};
