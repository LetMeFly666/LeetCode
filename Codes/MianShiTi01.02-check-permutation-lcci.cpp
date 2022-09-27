/*
 * @Author: LetMeFly
 * @Date: 2022-09-27 08:19:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-27 08:19:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool CheckPermutation(string& s1, string& s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};