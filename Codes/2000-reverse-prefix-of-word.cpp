/*
 * @Author: LetMeFly
 * @Date: 2022-02-02 10:20:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-02 10:23:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t t = word.find(ch, 0);
        if (t != word.npos)
            reverse(word.begin(), word.begin() + t + 1);
        return word;
    }
};