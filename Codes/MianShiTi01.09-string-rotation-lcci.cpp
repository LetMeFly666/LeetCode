/*
 * @Author: LetMeFly
 * @Date: 2022-09-29 12:18:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-29 12:20:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isFlipedString(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;
        return (s1 + s1).find(s2) != string::npos;
    }
};