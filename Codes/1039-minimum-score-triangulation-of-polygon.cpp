/*
 * @Author: LetMeFly
 * @Date: 2025-09-29 18:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-01 19:58:47
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

#if false  // this doesn't work
// 相邻两点乘积的和 + (n-1)条边乘积的2倍
// 但是不能相交
// 诶，好像直接最小的那个去连其他所有剩下的就好了
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int ans = values[0] * values.back();
        int m = values[0], loc = 0;
        for (int i = 1; i < values.size(); i++) {
            ans += values[i - 1] * values[i];
            if (values[i] < m) {
                m = values[i];
                loc = i;
            }
        }
        for (int i = 0; i < values.size(); i++) {
            if (abs(i - loc) > 1) {
                ans += m * values[i] * 2;
            }
        }
        return ans;
    }
};
#endif