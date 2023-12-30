/*
 * @Author: LetMeFly
 * @Date: 2023-12-30 16:17:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-30 17:03:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 1971年1月1日是周五
const string name[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
const int dayPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
private:
    bool ifRunNian(int year) {
        if (year % 4) {
            return false;
        }
        if (year % 100 == 0 && year % 400) {
            return false;
        }
        return true;
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        int nd = 1, nm = 1, ny = 1971;
        int index = 4;  // 周五
        while (nd != day || nm != month || ny != year) {
            index = (index + 1) % 7;
            nd++;
            int dayThisMonth = dayPerMonth[nm - 1];
            if (nm == 2 && ifRunNian(year)) {
                dayThisMonth = 29;
            }
            if (nd > dayThisMonth) {
                nd = 1;
                nm++;
                if (nm > 12) {
                    nm = 1;
                    ny++;
                }
            }
            // cout << nd << ", " << nm << ", " << ny << endl;
        }
        return name[index];
    }
};

#ifdef _WIN32
/*
15 8 1993

*/
int main() {
    int d, m, y;
    while (cin >> d >> m >> y) {
        Solution sol;
        cout << sol.dayOfTheWeek(d, m, y) << endl;
    }
    return 0;
}
#endif