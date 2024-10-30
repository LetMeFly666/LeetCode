/*
 * @Author: LetMeFly
 * @Date: 2024-10-30 12:23:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-30 12:27:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] > s[i] && s[i - 1] % 2 == s[i] % 2) {
                swap(s[i - 1], s[i]);
                return s;
            }
        }
        return s;
    }
};