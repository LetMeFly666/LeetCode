/*
 * @Author: LetMeFly
 * @Date: 2022-07-18 15:52:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-18 15:58:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows++;
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            ans.push_back({1});
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans.back();
    }
};
#else  // FirstTry
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int row = 1; row <= rowIndex; row++) {
            ans[row] = 1;
            for (int th = row - 1; th > 0; th--) {  // 必须是从后往前
                ans[th] += ans[th - 1];
            }
        }
        return ans;
    }
};
#endif  // FirstTry