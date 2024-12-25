/*
 * @Author: LetMeFly
 * @Date: 2024-12-25 18:08:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 18:40:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, int> ma;

    int dfs(int ia, int ib, int ja, int jb, vector<int>& h, vector<int>& v) {
        int code = ia + ib * 20 + ja * 400 + jb * 8000;
        if (ma.count(code)) {
            return ma[code];
        }
        int ans = 1000000000;
        if (ib - ia == 1 && jb - ja == 1) {
            ans = 0;
        }
        for (int ic = ia + 1; ic < ib; ic++) {
            ans = min(ans, h[ic - 1] + dfs(ia, ic, ja, jb, h, v) + dfs(ic, ib, ja, jb, h, v));
        }
        for (int jc = ja + 1; jc < jb; jc++) {
            ans = min(ans, v[jc - 1] + dfs(ia, ib, ja, jc, h, v) + dfs(ia, ib, jc, jb, h, v));
        }
        return ma[code] = ans;
    }
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        return dfs(0, m, 0, n, horizontalCut, verticalCut);
    }
};

#ifdef _WIN32
/*
3
2
[1,3]
[5]

13
*/
int main() {
    int a, b;
    string c, d;
    Solution sol;
    while (cin >> a >> b >> c >> d) {
        vector<int> va = stringToVector(c), vb = stringToVector(d);
        cout << sol.minimumCost(a, b, va, vb);
    }
    return 0;
}
#endif