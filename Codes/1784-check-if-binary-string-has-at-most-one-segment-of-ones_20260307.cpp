/*
 * @Author: LetMeFly
 * @Date: 2026-03-07 13:14:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-07 13:14:57
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1' && s[i - 1] == '0') {
                return false;
            }
        }
        return true;
    }
};