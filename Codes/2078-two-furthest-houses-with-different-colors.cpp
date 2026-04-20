/*
 * @Author: LetMeFly
 * @Date: 2026-04-20 21:48:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-20 21:51:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors.back()) {
            return n - 1;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] != colors[0]) {
                ans = max(ans, max(i, n - i - 1));
            }
        }
        return ans;
    }
};
