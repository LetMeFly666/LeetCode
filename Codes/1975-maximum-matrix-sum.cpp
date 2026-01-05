/*
 * @Author: LetMeFly
 * @Date: 2026-01-05 13:31:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-05 13:33:53
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        int maxiumNeg = -1000000;
        int cntNeg = 0;
        ll ans = 0;
        for (vector<int>& row : matrix) {
            for (int t : row) {
                ans += abs(t);
                if (t < 0) {
                    cntNeg++;
                    maxiumNeg = max(maxiumNeg, t);
                }
            }
        }
        if (cntNeg % 2) {
            ans += maxiumNeg * 2;
        }
        return ans;
    }
};