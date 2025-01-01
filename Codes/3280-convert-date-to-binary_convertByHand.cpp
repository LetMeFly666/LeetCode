/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:36:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:41:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string ten2two(string original) {
        int ten = 0;
        for (char c : original) {
            ten = ten * 10 + c - '0';
        }
        string ans;
        while (ten) {
            ans = char(ten % 2 + '0') + ans;
            ten >>= 1;
        }
        return ans;
    }
public:
    string convertDateToBinary(string date) {
        return ten2two(date.substr(0, 4)) + '-' + ten2two(date.substr(5, 2)) + '-' + ten2two(date.substr(8, 2));
    }
};