/*
 * @Author: LetMeFly
 * @Date: 2024-06-29 17:09:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-29 17:11:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string removeTrailingZeros(string num) {
        int loc = num.size() - 1;
        while (num[loc] == '0') {
            loc--;
        }
        return num.substr(0, loc + 1);
    }
};