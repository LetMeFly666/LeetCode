/*
 * @Author: LetMeFly
 * @Date: 2026-03-05 22:13:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-05 22:16:57
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(string s) {
        int c0 = 0, c1 = 0;
        for (int i = 0; i < s.size(); i++) {
            c0 += s[i] % 2 == i % 2;  // 不用减'0'就行
            c1 += s[i] % 2 != i % 2;
        }
        return min(c0, c1);
    }
};