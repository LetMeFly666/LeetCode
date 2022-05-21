/*
 * @Author: LetMeFly
 * @Date: 2022-01-05 08:49:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-05 08:55:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(char thisChar, string& s, int loc) {
        if (loc - 1 >= 0 && s[loc - 1] == thisChar) return false;
        if (loc + 1 < s.size() && s[loc + 1] == thisChar) return false;
        return true;
    }
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                char thisChar = 'a';
                while (!ok(thisChar, s, i)) {
                    thisChar++;
                }
                s[i] = thisChar;
            }
        }
        return s;
    }
};