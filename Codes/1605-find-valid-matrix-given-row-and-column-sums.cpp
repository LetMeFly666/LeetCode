/*
 * @Author: LetMeFly
 * @Date: 2023-03-14 12:48:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-14 12:49:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size()));
        for (int i = 0; i < rowSum.size(); i++) {
            for (int j = 0; j < colSum.size(); j++) {
                int thisVal = min(rowSum[i], colSum[j]);
                ans[i][j] = thisVal;
                rowSum[i] -= thisVal;
                colSum[j] -= thisVal;
            }
        }
        return ans;
    }
};