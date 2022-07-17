/*
 * @Author: LetMeFly
 * @Date: 2022-07-17 10:11:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-17 10:19:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            ans.push_back({1});
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};