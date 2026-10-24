/*
 * @Author: LetMeFly
 * @Date: 2026-10-24 12:01:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-24 12:29:12
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    inline int parse(const string& s) {
        int m = (s[0] - '0') * 10 + s[1] - '0', d = (s[3] - '0') * 10 + s[4] - '0';
        int ans = d;
        for (int i = 0; i < m - 1; i++) {
            ans += days[i];
        }
        return ans;
    }
public:
    int countDaysTogether(const string& arriveAlice, const string& leaveAlice, const string& arriveBob, const string& leaveBob) {
        int aa = parse(arriveAlice), al = parse(leaveAlice);
        int ba = parse(arriveBob), bl = parse(leaveBob);
        return max(0, min(al, bl) - max(aa, ba) + 1);
    }
};
