/*
 * @Author: LetMeFly
 * @Date: 2026-03-07 17:46:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-07 17:46:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minFlips(string s) {
        int o1 = 0, o2 = 0;
        for (int i = 0; i < s.size(); i++) {
            o1 += s[i] % 2 == i % 2;
            o2 += s[i] % 2 != i % 2;
        }
        return min(o1, o2);
    }
};