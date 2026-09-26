/*
 * @Author: LetMeFly
 * @Date: 2026-01-13 21:41:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-13 22:21:20
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
            double to = s[1] + s[2];
            total += max(0., (to - from) * s[2]);
            // printf("(%llf -> %llf), total = %llf\n", from, to, total);
        }

        return total > half;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total = 0;  // !!!!!记得初始化
        for (vector<int>& s : squares) {
            total += ((long long) s[2]) * s[2];
        }
        this->squares = move(squares);
        half = 1. * total / 2;

        double l = 0, r = 1000000000;
        for (int _ = 0; _ < 50; _++) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
            // printf("l = %llf, r = %llf, mid = %llf\n", l, r, mid);
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

#if defined(_WIN32) || defined(__APPLE__)
/*
[[0,0,1],[2,2,1]]

*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> a = stringToVectorVector(s);
        Solution sol;
        cout << sol.separateSquares(a) << endl;
    }
    return 0;
}
#endif