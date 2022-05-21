/*
 * @Author: LetMeFly
 * @Date: 2022-01-15 11:37:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-15 11:38:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int week = 1;
        int day = 0;
        while (n--) {
            ans += week + day;
            day++;
            if (day == 7) {
                day = 0;
                week++;
            }
        }
        return ans;
    }
};