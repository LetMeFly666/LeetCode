/*
 * @Author: LetMeFly
 * @Date: 2023-11-30 20:38:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-30 20:41:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int bin1[26] = {0}, bin2[26] = {0};
        for (char c : word1) {
            bin1[c - 'a']++;
        }
        for (char c : word2) {
            bin2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if ((bin1[i] || 0) != (bin2[i] || 0)) {
                return false;
            }
        }
        sort(bin1, bin1 + 26);
        sort(bin2, bin2 + 26);
        for (int i = 0; i < 26; i++) {
            if (bin1[i] != bin2[i]) {
                return false;
            }
        }
        return true;
    }
};