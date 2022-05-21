/*
 * @Author: LetMeFly
 * @Date: 2022-04-20 14:56:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-20 15:00:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int JinWei = 0;
        int l2 = num2.size();
        int l1 = num1.size();
        while (l2 || l1) {
            if (l1) {
                JinWei += num1[--l1] - '0';
            }
            if (l2) {
                JinWei += num2[--l2] - '0';
            }
            ans = (char)(JinWei % 10 + '0') + ans;
            JinWei /= 10;
        }
        if (JinWei)
            ans = (char)(JinWei % 10 + '0') + ans;
        return ans;
    }
};