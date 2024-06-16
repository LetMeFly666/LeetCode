/*
 * @Author: LetMeFly
 * @Date: 2024-06-16 18:15:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-16 18:15:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};