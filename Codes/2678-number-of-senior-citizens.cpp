/*
 * @Author: LetMeFly
 * @Date: 2023-10-23 13:22:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-23 13:24:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (string& d : details) {
            ans += (d[11] - '0') * 10 + (d[12] - '0') > 60;
        }
        return ans;
    }
};