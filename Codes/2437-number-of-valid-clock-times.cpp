/*
 * @Author: LetMeFly
 * @Date: 2023-05-09 09:33:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-09 09:54:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一，特判计算
class Solution {
private:
    int getHour(char a, char b) {
        if (a == '?' && b == '?') {
            return 24;
        }
        if (a == '?') {
            return '0' <= b && b <= '3' ? 3 : 2;
        }
        if (b == '?') {
            return a == '0' || a == '1' ? 10 : 4;
        }
        return 1;
    }

    int getMin(char a, char b) {
        if (a == '?' && b == '?') {
            return 60;
        }
        if (a == '?') {
            return 6;
        }
        if (b == '?') {
            return 10;
        }
        return 1;
    }
public:
    int countTime(string time) {
        return getHour(time[0], time[1]) * getMin(time[3], time[4]);
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    bool canChangeTo(string oldTime, string newTime) {
        for (int i = 0; i < 5; i++) {
            if (oldTime[i] != newTime[i] && oldTime[i] != '?') {
                return false;
            }
        }
        return true;
    }
public:
    int countTime(string time) {
        int ans = 0;
        for (int h = 0; h < 24; h++) {
            for (int m = 0; m < 60; m++) {
                string thisTime = string("") + (char)('0' + h / 10) + (char)('0' + h % 10) + ':' + (char)('0' + m / 10) + (char)('0' + m % 10);
                ans += canChangeTo(time, thisTime);
            }
        }
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
0?:0?
?5:00
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.countTime(s) << endl;
    }
    return 0;
}
#endif