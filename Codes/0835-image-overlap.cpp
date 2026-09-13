/*
 * @Author: LetMeFly
 * @Date: 2026-09-13 11:21:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-13 11:31:07
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for (int dx = n - 1; dx < n; dx++) {
            for (int dy = n - 1; dy < n; dy++) {
                int this_ans = 0;
                // img1[i][j] -> img2[i+dx][j+dy]
                // 0≤i<n 且 0≤i+dx<n 得出 0≤i -dx≤i i<n i<n-dx
                for (int i = max(0, -dx); i < min(n, n-dx); i++) {
                    for (int j = max(0, -dy); j < min(n, n-dy); j++) {
                        this_ans += img1[i][j] * img2[i+dx][j+dy];
                    }
                }
                ans = max(ans, this_ans);
            }
        }
        return ans;
    }
};
