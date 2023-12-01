/*
 * @Author: LetMeFly
 * @Date: 2023-12-01 10:02:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-01 10:21:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> a(m * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[mat[i][j] - 1] = {i, j};
            }
        }
        vector<int> cntRow(n), cntCol(m);
        for (int i = 0; i < arr.size(); i++) {
            int t = arr[i] - 1;
            cntRow[a[t].first]++;
            cntCol[a[t].second]++;
            if (cntRow[a[t].first] == m || cntCol[a[t].second] == n) {
                return i;
            }
        }
        return -1;  // Fake Return
    }
};