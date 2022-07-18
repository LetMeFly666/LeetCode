/*
 * @Author: LetMeFly
 * @Date: 2022-07-18 16:16:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-18 16:22:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        #ifdef FirstTry
        int ans = triangle[n - 1][0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, triangle[n - 1][i]);
        }
        return ans;
        #else
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
        #endif
    }
};