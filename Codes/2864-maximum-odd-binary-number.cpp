/*
 * @Author: LetMeFly
 * @Date: 2024-03-13 08:34:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-13 08:38:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = count(s.begin(), s.end(), '1');
        return string(cnt1 - 1, '1') + string(s.size() - cnt1, '0') + '1';
    }
};