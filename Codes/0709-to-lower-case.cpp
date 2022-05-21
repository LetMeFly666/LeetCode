/*
 * @Author: LetMeFly
 * @Date: 2021-12-12 06:13:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-12 06:14:19
 */
#include "_[1,2]toVector.h"

class Solution {
public:
    string toLowerCase(string& s) {
        for (char& c : s)
            if (c >= 'A' && c <= 'Z')
                c += 32;
        return s;
    }
};