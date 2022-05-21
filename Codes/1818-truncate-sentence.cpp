/*
 * @Author: LetMeFly
 * @Date: 2021-12-06 09:57:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-06 10:00:27
 */
#include "_[1,2]toVector.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        s += ' ';
        int loc = 0;
        while (k > 0) {
            if (s[loc++] == ' ')
                k--;
        }
        return s.substr(0, loc - 1);
    }
};