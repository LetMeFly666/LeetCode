/*
 * @Author: LetMeFly
 * @Date: 2025-12-11 13:14:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-11 13:23:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xm(100001, 100001), xM(100001), ym(100001, 100001), yM(100001);
        for (vector<int>& building : buildings) {
            int x = building[0], y = building[1];
            xm[x] = min(xm[x], y);
            xM[x] = max(xM[x], y);
            ym[y] = min(ym[y], x);
            yM[y] = max(yM[y], x);
        }
        int ans = 0;
        for (vector<int>& building : buildings) {
            int x = building[0], y = building[1];
            ans += xm[x] < y && y < xM[x] && ym[y] < x && x < yM[y];
        }
        return ans;
    }
};