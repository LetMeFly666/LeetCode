/*
 * @Author: LetMeFly
 * @Date: 2025-02-19 17:37:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-19 17:46:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
---- 
       -----


-------
    -------


--------
 ----
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mLeft = 100000, MRight = -100000;
        for (vector<int>& a : arrays) {
            ans = max(ans, max(a.back() - mLeft, MRight - a[0]));
            mLeft = min(mLeft, a[0]), MRight = max(MRight, a.back());
        }
        return ans;
    }
};