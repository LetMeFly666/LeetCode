/*
 * @Author: LetMeFly
 * @Date: 2022-03-07 16:00:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-07 16:02:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) 
            return "0";
        string ans;
        bool fu = false;
        if (num < 0) 
            fu = true, num = -num;
        while (num) {
            ans = char(num % 7 + '0') + ans;
            num /= 7;
        }
        if (fu)
            ans = "-" + ans;
        return ans;
    }
};