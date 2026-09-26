/*
 * @Author: LetMeFly
 * @Date: 2026-08-23 13:39:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-23 13:46:29
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
class Solution {
private:
    pii cal(string& s, int l, int r) {
        int val = 0, cnt = 0;
        for (int i = l; i < r; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                val += s[i] - '0';
            } else {
                cnt++;
            }
        }
        return {val, cnt};
    }

    int getM(int n) {
        return 9 * ((n + 1) / 2);
    }

    int getm(int n) {
        return 9 * (n / 2);
    }
public:
    bool sumGame(string& num) {
        int n = num.size();
        auto [val1, cnt1] = cal(num, 0, n / 2);
        auto [val2, cnt2] = cal(num, n / 2, n);
        if (cnt1 > cnt2) {
            swap(val1, val2);
            swap(cnt1, cnt2);
        }
        int diff = val1 - val2, times = cnt2 - cnt1;
        int M = getM(times), m = getm(times);
        return M > diff || m < diff;
    }
};
