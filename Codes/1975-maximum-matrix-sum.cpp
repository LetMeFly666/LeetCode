/*
 * @Author: LetMeFly
 * @Date: 2026-01-05 13:31:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-05 13:39:00
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        int minimum = 1000000;
        int cntNeg = 0;
        ll ans = 0;
        for (vector<int>& row : matrix) {
            for (int t : row) {
                ans += abs(t);
                if (t < 0) {
                    cntNeg++;
                }
                minimum = min(minimum, abs(t));
            }
        }
        if (cntNeg % 2) {
            ans -= minimum * 2;
        }
        return ans;
    }
};

/*
[[-1,0,-1],[-2,1,3],[3,2,2]]

-1 0 -1
-2 1 3
3  2 2
*/

/*
[[2,9,3],[5,4,-4],[1,7,1]]

2 9 3
5 4 -4
1 7 1

34
*/