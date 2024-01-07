/*
 * @Author: LetMeFly
 * @Date: 2024-01-07 12:37:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-07 12:43:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for (char c : magazine) {
            cnt[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (!cnt[c - 'a']) {
                return false;
            }
            cnt[c - 'a']--;
        }
        return true;
    }
};