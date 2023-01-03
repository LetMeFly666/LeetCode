/*
 * @Author: LetMeFly
 * @Date: 2023-01-03 18:53:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-03 19:17:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool areNumbersAscending(string s) {
        int lastVal = 0;
        int thisVal = 0;
        for (char c : s) {
            if (isdigit(c)) {
                thisVal = thisVal * 10 + c - '0';
            }
            else {
                if (thisVal) {  // 数字转字母
                    if (lastVal >= thisVal)
                        return false;
                    lastVal = thisVal;
                    thisVal = 0;
                }
            }
        }
        if (thisVal) {
            if (lastVal >= thisVal)
                return false;
        }
        return true;
    }
};