/*
 * @Author: LetMeFly
 * @Date: 2025-09-15 21:48:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-15 21:50:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> cannot(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        bool can = true;
        for (char c : text) {
            if (c == ' ') {
                ans += can;
                can = true;
                continue;
            }
            if (cannot.count(c)) {
                can = false;
            }
        }
        return ans + can;
    }
};