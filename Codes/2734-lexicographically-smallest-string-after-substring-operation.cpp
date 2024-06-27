/*
 * @Author: LetMeFly
 * @Date: 2024-06-27 22:13:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-27 22:25:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string smallestString(string s) {
        bool changing = false;
        int loc = 0;
        while (loc < s.size() && s[loc] == 'a') {
            loc++;
        }
        if (loc == s.size()) {  // 特判：全a的情况
            s.back() = 'z';
            return s;
        }
        for (; loc < s.size() && s[loc] != 'a'; loc++) {
            s[loc]--;
        }
        return s;
    }
};