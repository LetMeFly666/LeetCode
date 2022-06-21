/*
 * @Author: LetMeFly
 * @Date: 2022-06-21 09:42:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-21 09:42:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (char& c : address) {
            if (c == '.')
                ans += "[.]";
            else
                ans += c;
        }
        return ans;
    }
};