/*
 * @Author: LetMeFly
 * @Date: 2023-07-17 08:25:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-17 08:27:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string addStrings(string num1, string num2) {
        int loc1 = num1.size() - 1, loc2 = num2.size() - 1;
        int add = 0;
        string ans;
        while (loc1 >= 0 || loc2 >= 0 || add) {
            if (loc1 >= 0) {
                add += num1[loc1--] - '0';
            }
            if (loc2 >= 0) {
                add += num2[loc2--] - '0';
            }
            ans = (char)('0' + add % 10) + ans;
            add /= 10;
        }
        return ans;
    }
};