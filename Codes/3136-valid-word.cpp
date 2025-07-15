/*
 * @Author: LetMeFly
 * @Date: 2025-07-15 23:15:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-15 23:20:33
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'o' || c == 'u';
    }
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool hasYuan = false, hasFu = false;
        for (char c : word) {
            if ('A' <= c && c <= 'Z') {
                // python -c "print(ord('a') - ord('A'))"
                c += 32;
            }
            if ('a' <= c && c <= 'z') {
                if (isYuan(c)) {
                    hasYuan = true;
                } else {
                    hasFu = true;
                }
            } else if (c < '0' || c > '9') {
                return false;
            }
        }
        return hasYuan && hasFu;
    }
};