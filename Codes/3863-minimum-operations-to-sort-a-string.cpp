/*
 * @Author: LetMeFly
 * @Date: 2026-10-21 08:00:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-21 08:01:24
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(const string& s) {
        char mn = 'z', mx = 'a';
        bool already = true;
        char last = 'a';
        for (char c : s) {
            if (c < last) {
                already = false;
            }
            last = c;
            mn = min(mn, c);
            mx = max(mx, c);
        }
        if (already) {
            return 0;
        }
        if (s.size() == 2) {
            return -1;
        }
        return s[0] != mn && s.back() != mx ? 2 : 1;
    }
};
