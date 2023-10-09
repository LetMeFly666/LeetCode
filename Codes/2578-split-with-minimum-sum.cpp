/*
 * @Author: LetMeFly
 * @Date: 2023-10-09 09:06:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-09 09:09:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string n1, n2;
        for (int i = 0; i < s.size(); i++) {
            (i % 2 ? n2 : n1) += s[i];
        }
        // cout << "n1: " << n1 << ", n2: " << n2 << endl;  //**********
        return atoi(n1.c_str()) + atoi(n2.c_str());
    }
};