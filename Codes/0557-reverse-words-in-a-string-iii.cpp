/*
 * @Author: LetMeFly
 * @Date: 2023-03-14 13:46:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-14 13:49:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reverseWords(string& s) {
        int begin = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        return s;
    }
};