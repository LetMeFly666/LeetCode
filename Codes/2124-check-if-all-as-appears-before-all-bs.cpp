/*
 * @Author: LetMeFly
 * @Date: 2026-11-22 09:57:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-22 09:57:56
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkString(const string& s) {
        for (int i = 1, n = s.size(); i < n; i++) {
            if (s[i - 1] == 'b' && s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};
