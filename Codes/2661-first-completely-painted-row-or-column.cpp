/*
 * @Author: LetMeFly
 * @Date: 2023-12-01 10:02:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-01 10:16:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> val2index(m * n + 1);
        for (int i = 0; i < arr.size(); i++) {
            val2index[arr[i]] = i;
        }
        vector<pair<int, int>> a(m * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[mat[i][j] - 1] = {i, j};
            }
        }
        vector<int> cntRow(n), cntCol(m);
        int firstRow = -1, firstCol = -1;
        for (int t : arr) {
            t--;
            cntRow[a[t].first]++;
            if (cntRow[a[t].first] == m && firstRow == -1) {
                firstRow = a[t].first;
            }
            cntCol[a[t].second]++;
            if (cntCol[a[t].second] == n && firstCol == -1) {
                firstCol = a[t].second;
            }
            if (firstRow != -1 && firstCol != -1) {
                printf("firstRow = %d, firstCol = %d\n", firstRow, firstCol);  //****
                return val2index[mat[firstRow][firstCol]];
            }
        }
        return -1;  // Fake Return
    }
};