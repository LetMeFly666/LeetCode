/*
 * @Author: LetMeFly
 * @Date: 2026-01-17 20:01:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-17 20:02:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    // a->b VS c->d
    ll getDiff(int a, int b, int c, int d) {
        return max(0, min(b, d) - max(a, c));
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                ll dx = getDiff(bottomLeft[i][0], topRight[i][0], bottomLeft[j][0], topRight[j][0]);
                ll dy = getDiff(bottomLeft[i][1], topRight[i][1], bottomLeft[j][1], topRight[j][1]);
                ans = max(ans, min(dx, dy) * min(dx, dy));
            }
        }
        return ans;
    }
};