/*
 * @Author: LetMeFly
 * @Date: 2024-01-07 12:37:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-07 12:39:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c : magazine) {
            cnt2[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (!cnt2[c - 'a']) {
                return false;
            }
            cnt2[c - 'a']--;
        }
        return true;
    }
};