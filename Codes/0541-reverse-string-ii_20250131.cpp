/*
 * @Author: LetMeFly
 * @Date: 2025-01-31 11:58:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-31 12:02:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline void reverse_(string& s, int l, int r) {
        reverse(s.begin() + l, s.begin() + r);
    }
public:
    string reverseStr(string& s, int k) {
        for (int l = 0; l < s.size(); l += k * 2) {
            reverse_(s, l, min(l + k, (int)s.size()));
        }
        return s;
    }
};