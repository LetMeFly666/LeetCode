/*
 * @Author: LetMeFly
 * @Date: 2022-10-14 11:00:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-14 11:56:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 较长
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        int maskMin = (1 << 6) - 1;
        int maskHour = (1 << 10) - 1 - maskMin;
        for (int state = 0; state < 1024; state++) {
            int cnt1 = 0;
            for (int i = 0; i < 10; i++) {
                if (state & (1 << i)) {
                    cnt1++;
                }
            }
            if (cnt1 != turnedOn) {
                continue;
            }
            int hour = (state & maskHour) >> 6;
            int minute = state & maskMin;
            if (hour < 12 && minute < 60) {
                ans.push_back(to_string(hour) + ':' + (char)(minute / 10 + '0') + (char)(minute % 10 + '0'));
            }
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 用上__builtin_popcount、优化取高位的方式
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int mask = 0; mask < 1024; mask++) {
            if (__builtin_popcount(mask) != turnedOn)
                continue;
            int hour = mask >> 6;
            int minute = mask & 63;
            if (hour < 12 && minute < 60) {
                ans.push_back(to_string(hour) + ':' + (char)(minute / 10 + '0') + (char)(minute % 10 + '0'));
            }
        }
        return ans;
    }
};
#else  // SecondTry
// ThirdTry  // 枚举小时和分钟
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
                    ans.push_back(to_string(hour) + ':' + (char)(minute / 10 + '0') + (char)(minute % 10 + '0'));
                }
            }
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry