/*
 * @Author: LetMeFly
 * @Date: 2026-03-29 19:32:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-29 19:41:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif
#include <iostream>
class Solution {
private:
    inline bool same2(const string& a, const string& b, int i, int j) {
        return a[i] == b[i] && a[j] == b[j] || a[i] == b[j] && a[j] == b[i];
    }
public:
    bool canBeEqual(const string& s1, const string& s2) {
        return same2(s1, s2, 0, 2) && same2(s1, s2, 1, 3);
    }
};