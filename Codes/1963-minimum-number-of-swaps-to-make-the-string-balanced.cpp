/*
 * @Author: LetMeFly
 * @Date: 2025-03-17 12:16:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-17 12:17:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minSwaps(string s) {
        int zuoQianYou = 0, zuo = 0;
        for (char c : s) {
            if (c == '[') {
                zuo++;
            } else {
                if (zuo) {
                    zuo--;
                } else {
                    zuoQianYou++;
                }
            }
        }
        return (zuoQianYou + 1) / 2;
    }
};