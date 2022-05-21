/*
 * @Author: LetMeFly
 * @Date: 2021-12-21 08:31:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-21 08:36:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
public:
    int dayOfYear(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        auto isLeapYear = [&](){
            if (year % 4) return false;
            if (year % 100 == 0) return year % 400 == 0;
            return true;
        };
        if (isLeapYear()) days[1] = 29;
        else days[1] = 28;
        int ans = day;
        for (int i = 0; i + 1 < month; i++) 
            ans += days[i];
        return ans;
    }
};