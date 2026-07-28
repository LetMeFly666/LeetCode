/*
 * @Author: LetMeFly
 * @Date: 2026-07-28 21:34:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-28 21:36:51
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string smallestPalindrome(string& s) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int idx = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                s[idx++] = i + 'a';
            }
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                s[idx++] = i + 'a';
            }
        }

        return s;
    }
};
