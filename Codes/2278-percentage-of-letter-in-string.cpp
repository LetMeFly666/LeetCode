/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 13:28:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 13:29:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (char c : s) {
            cnt += c == letter;
        }
        return cnt * 100 / s.size();
    }
};