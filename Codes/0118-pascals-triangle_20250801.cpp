/*
 * @Author: LetMeFly
 * @Date: 2025-08-01 23:51:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-01 23:55:15
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            ans[i].push_back(1);
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};