/*
 * @Author: LetMeFly
 * @Date: 2022-10-24 19:37:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-24 19:37:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool repeatedSubstringPattern(string& s) {
        return (s + s).find(s, 1) != s.size();
    }
};