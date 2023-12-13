/*
 * @Author: LetMeFly
 * @Date: 2023-12-13 09:35:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-13 09:38:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string makeSmallestPalindrome(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                s[i] = s[s.size() - i - 1] = min(s[i], s[s.size() - i - 1]);
            }
        }
        return s;
    }
};