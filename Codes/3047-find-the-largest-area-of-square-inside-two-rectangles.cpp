/*
 * @Author: LetMeFly
 * @Date: 2026-01-17 19:45:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-17 19:51:43
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
typedef long long ll;

class Solution {
private:
    // a->b VS c->d
    ll getDiff(int a, int b, int c, int d) {
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        if (c > b) {
            return 0;
        }
        return min(b, d) - c;
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                ll dx = getDiff(bottomLeft[i][0], topRight[i][0], bottomLeft[j][0], topRight[j][0]);
                ll dy = getDiff(bottomLeft[i][1], topRight[i][1], bottomLeft[j][1], topRight[j][1]);
                ans = max(ans, dx * dy);
            }
        }
        return ans;
    }
};