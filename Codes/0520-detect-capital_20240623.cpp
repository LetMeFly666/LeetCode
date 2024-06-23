/*
 * @Author: LetMeFly
 * @Date: 2024-06-23 18:49:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-23 18:52:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool detectCapitalUse(string& word) {
        bool small = true, big = true;
        for (int i = 1; i < word.size(); i++) {
            if (islower(word[i])) {
                big = false;
            }
            else {
                small = false;
            }
        }
        return small || (big && isupper(word[0]));
    }
};