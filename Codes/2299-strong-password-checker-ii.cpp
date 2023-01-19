/*
 * @Author: LetMeFly
 * @Date: 2023-01-19 22:31:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-19 22:48:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool strongPasswordCheckerII(string& password) {
        if (password.size() < 8)
            return false;
        char lastChar = 0;
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        for (char c : password) {
            if (c == lastChar)
                return false;
            lastChar = c;
            if (c >= '0' && c <= '9')
                hasDigit = true;
            else if (c >= 'a' && c <= 'z')
                hasLower = true;
            else if (c >= 'A' && c <= 'Z')
                hasUpper = true;
            else
                hasSpecial = true;
        }
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};