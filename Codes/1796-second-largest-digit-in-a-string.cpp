/*
 * @Author: LetMeFly
 * @Date: 2022-12-03 12:19:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-03 12:23:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int secondHighest(string& s) {
        bool bin[10] = {false};
        for (char c : s) {
            if (c >= '0' && c <= '9')
                bin[c - '0'] = true;
        }
        bool foundFirst = false;
        for (int i = 9; i >= 0; i--) {
            if (bin[i]) {
                if (foundFirst) {
                    return i;
                }
                else {
                    foundFirst = true;
                }
            }
        }
        return -1;
    }
};