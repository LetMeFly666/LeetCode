/*
 * @Author: LetMeFly
 * @Date: 2023-04-17 10:04:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-17 10:08:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int dayPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
private:
    int stringToInt(string& s) {
        int m, d;
        sscanf(s.c_str(), "%d-%d", &m, &d);
        int ans = 0;
        for (int i = 1; i < m; i++) {
            ans += dayPerMonth[i - 1];
        }
        ans += d;
        return ans;
    }
public:
    int countDaysTogether(string& arriveAlice, string& leaveAlice, string& arriveBob, string& leaveBob) {
        int aa = stringToInt(arriveAlice), la = stringToInt(leaveAlice);
        int ab = stringToInt(arriveBob), lb = stringToInt(leaveBob);
        if (aa > ab) {
            swap(aa, ab);
            swap(la, lb);
        }
        if (ab > la) {
            return 0;
        }
        return min(lb, la) - ab + 1;
    }
};