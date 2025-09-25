/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:20:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:21:43
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};