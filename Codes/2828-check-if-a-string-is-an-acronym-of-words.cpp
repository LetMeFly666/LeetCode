/*
 * @Author: LetMeFly
 * @Date: 2023-12-20 14:05:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-20 14:05:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != words[i][0]) {
                return false;
            }
        }
        return true;
    }
};