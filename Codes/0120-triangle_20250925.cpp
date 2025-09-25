/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:16:48
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int toAdd = triangle[i - 1][j];
                if (j - 1 >= 0) {
                    toAdd = min(toAdd, triangle[i - 1][j - 1]);
                }
                triangle[i][j] += toAdd;
            }
        }
        int ans = 100000;
        for (int t : triangle.back()) {
            ans = min(ans, t);
        }
        return ans;
    }
};