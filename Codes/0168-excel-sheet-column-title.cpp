/*
 * @Author: LetMeFly
 * @Date: 2022-08-04 11:19:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-04 11:23:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (--columnNumber >= 0) {
            ans = (char)(columnNumber % 26 + 'A') + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};