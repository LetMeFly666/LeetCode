/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:43:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:48:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string ten2two(string s) {
        int a = stoi(s);
        string temp = bitset<32>(a).to_string();
        return temp.substr(temp.find('1'));
    }
public:
    string convertDateToBinary(string date) {
        return ten2two(date.substr(0, 4)) + '-' + ten2two(date.substr(5, 2)) + '-' + ten2two(date.substr(8, 2));
    }
};