/*
 * @Author: LetMeFly
 * @Date: 2022-01-03 08:20:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-03 08:44:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool runnian(int year) {
        if (year % 4) return false;
        if (year % 100 == 0) return year % 400 == 0;
        return true;
    }
    /* LeetCode一周的第一天是从周日开始的！！！ */
    string zhou[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    /* 1971.1.1 周五(zhou[4]), 1970.12.31 周四(zhou[3]) */
    string dayOfTheWeek(int day, int month, int year) {
        int z = 3;
        for (int y = 1971; y < year; y++)
            z += runnian(y) ? 366 : 365; /* 闰年有366天！ */
        days[1] = runnian(year) ? 29 : 28; /* 闰年2月是29天！ */
        for (int m = 0; m + 1 < month; m++)
            z += days[m];
        z += day;
        return zhou[z % 7];
    }
};

#ifdef _WIN32
int main() {
    int day, month, year;
    while (cin >> day >> month >> year) {
        Solution sol;
        cout << sol.dayOfTheWeek(day, month, year) << endl;
    }
    return 0;
}
#endif