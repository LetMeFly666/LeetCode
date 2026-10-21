/*
 * @Author: LetMeFly
 * @Date: 2026-10-21 08:00:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-21 08:05:50
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
        if (s[0] == mn || s.back() == mx) {
            return 1;
        }
        bool middle_ok = false;
        for (int i = 1, n = s.size(); i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                middle_ok = true;
                break;
            }
        }
        return middle_ok ? 2 : 3;
    }
};
