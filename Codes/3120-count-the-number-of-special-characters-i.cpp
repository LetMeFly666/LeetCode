/*
 * @Author: LetMeFly
 * @Date: 2026-05-26 23:50:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-26 23:53:14
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {false}, upper[26] = {false};
        for (char c : word) {
            if ('a' <= c && c <= 'z') {
                lower[c - 'a'] = true;
            } else {
                upper[c - 'A'] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += lower[i] && upper[i];
        }
        return ans;
    }
};
