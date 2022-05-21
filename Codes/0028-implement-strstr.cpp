/*
 * @Author: LetMeFly
 * @Date: 2022-05-15 08:47:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-15 08:48:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int strStr(string& haystack, string& needle) {
        return haystack.find(needle);
    }
};