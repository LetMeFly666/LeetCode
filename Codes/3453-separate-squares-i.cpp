/*
 * @Author: LetMeFly
 * @Date: 2026-01-13 21:41:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-13 22:08:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    double half = 0;
    vector<vector<int>> squares;

    bool check(double h) {
        double total = 0;
        for (vector<int>& s : squares) {
            double from = max(double(s[1]), h);
            double to = s[0] + s[1];
            total += max(0., (to - from) * s[1]);
        }

        return total > half;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total;
        for (vector<int>& s : squares) {
            total += ((long long) s[2]) * s[2];
        }
        this->squares = move(squares);
        half = 1. * total / 2;

        double l = 0, r = 1000000000;
        for (int _ = 0; _ < 50; _++) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};

/*
>>> 10**9 / 2**46
1.4210854715202004e-05
>>> 10**9 / 2**47
7.105427357601002e-06
*/