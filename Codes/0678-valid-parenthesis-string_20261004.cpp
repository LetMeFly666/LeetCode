/*
 * @Author: LetMeFly
 * @Date: 2026-10-04 17:57:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-04 17:59:19
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkValidString(const string& s) {
        int mx = 0, mn = 0;
        for (char c : s) {
            if (c == '(') {
                mx++, mn++;
            } else if (c == ')') {
                mx--, mn--;
                if (mx < 0) {
                    return false;
                }
            } else {
                mx++, mn--;
            }
            mn = max(mn, 0);
        }
        return !mn;
    }
};
