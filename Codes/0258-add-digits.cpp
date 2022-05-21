/*
 * @Author: LetMeFly
 * @Date: 2022-03-03 12:59:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-03 13:00:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int s = 0;
            while (num) {
                s += num % 10;
                num /= 10;
            }
            num = s;
        }
        return num;
    }
};