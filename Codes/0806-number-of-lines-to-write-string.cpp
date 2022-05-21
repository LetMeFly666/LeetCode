/*
 * @Author: LetMeFly
 * @Date: 2022-04-12 09:58:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-12 10:00:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int cntLine = 1;
        int remain = 100;
        for (char& c : s) {
            int thisWidth = widths[c - 'a'];
            if (thisWidth > remain) {
                cntLine++;
                remain = 100 - thisWidth;
            }
            else {
                remain -= thisWidth;
            }
        }
        return {cntLine, 100 - remain};
    }
};