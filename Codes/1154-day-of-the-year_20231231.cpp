/*
 * @Author: LetMeFly
 * @Date: 2023-12-31 12:30:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-31 12:35:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int dayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isRunNian(int y) {
        if (y % 100 == 0) {
            return y % 400 == 0;
        }
        return y % 4 == 0;
    }

public:
    int dayOfYear(string date) {
        int y, m, d;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        if (isRunNian(y)) {
            dayOfMonth[1] = 29;
        }
        int ans = 0;
        for (int i = 1; i < m; i++) {
            ans += dayOfMonth[i - 1];
        }
        ans += d;
        return ans;
    }
};