/*
 * @Author: LetMeFly
 * @Date: 2026-10-21 08:00:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-21 17:05:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(const string& s) {
        char mn = 'z' + 1, mx = 'a' - 1;
        bool already = true;
        int cnt_mn = 0, cnt_mx = 0;
        char last = 'a';
        for (char c : s) {
            if (c < last) {
                already = false;
            }
            last = c;

            if (c < mn) {
                mn = c;
                cnt_mn = 1;
            } else if (c == mn) {
                cnt_mn++;
            }

            if (c > mn) {
                mx = c;
                cnt_mx = 1;
            } else if (c == mx) {
                cnt_mx++;
            }
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
        if (cnt_mn == 1 && cnt_mx == 1 && s[0] == mx && s.back() == mn) {
            return 3;
        }
        return 2;
    }
};
