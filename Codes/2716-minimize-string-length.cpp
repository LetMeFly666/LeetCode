/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:26:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:26:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimizedStringLength(string s) {
        return set(s.begin(), s.end()).size();
    }
};