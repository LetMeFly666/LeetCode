/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:19:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;  // 记得break
            }
        }
        return atoi(s.c_str());
    }
};