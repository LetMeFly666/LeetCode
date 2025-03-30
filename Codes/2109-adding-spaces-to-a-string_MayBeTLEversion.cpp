/*
 * @Author: LetMeFly
 * @Date: 2025-03-30 16:51:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-30 16:53:16
 * @Description: 可能会TLE的做法，试试C++字符串的insert
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int cnt = 0;
        for (int t : spaces) {
            s.insert(s.begin() + (cnt++ + t), ' ');
        }
        return s;
    }
};