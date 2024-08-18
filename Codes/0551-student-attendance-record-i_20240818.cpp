/*
 * @Author: LetMeFly
 * @Date: 2024-08-18 23:40:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-18 23:41:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkRecord(string& s) {
        int cntA = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                cntA++;
                if (cntA >= 2) {
                    return false;
                }
            }
            if (i >= 2 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') {
                return false;
            }
        }
        return true;
    }
};