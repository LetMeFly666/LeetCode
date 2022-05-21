/*
 * @Author: LetMeFly
 * @Date: 2022-04-22 08:40:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-22 08:40:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};