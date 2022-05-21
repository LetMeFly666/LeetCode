/*
 * @Author: LetMeFly
 * @Date: 2022-04-07 08:10:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-07 08:13:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            bool same = true;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != goal[(i + j) % s.size()]) {
                    same = false;
                    break;
                }
            }
            if (same)
                return true;
        }
        return false;
    }
};