/*
 * @Author: LetMeFly
 * @Date: 2026-07-28 21:34:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-28 21:41:30
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
        
        char middle = 0;
        if (s.size() % 2) {
            middle = s[s.size() / 2];
        }

        int idx = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                s[idx++] = i + 'a';
            }
        }
        if (middle) {
            s[idx++] = middle;
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                s[idx++] = i + 'a';
            }
        }

        return s;
    }
};
