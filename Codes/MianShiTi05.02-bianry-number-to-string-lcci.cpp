/*
 * @Author: LetMeFly
 * @Date: 2023-03-02 09:35:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-02 09:38:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (true) {
            num *= 2;
            int thisVal = num >= 1;
            ans += (char)('0' + thisVal);
            num -= thisVal;
            if (num == 0) {
                return ans;
            }
            if (ans.size() == 32) {
                return "ERROR";
            }
        }
    }
};