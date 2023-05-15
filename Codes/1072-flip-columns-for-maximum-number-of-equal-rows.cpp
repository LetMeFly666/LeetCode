/*
 * @Author: LetMeFly
 * @Date: 2023-05-15 10:46:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-15 10:53:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<vector<bool>, int> ma;
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> thisLine(m);
            for (int j = 0; j < m; j++) {
                thisLine[j] = matrix[i][j] ^ matrix[i][0];
            }
            ma[thisLine]++;
            ans = max(ans, ma[thisLine]);
        }
        return ans;
    }
};