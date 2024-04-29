/*
 * @Author: LetMeFly
 * @Date: 2024-04-29 12:37:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-29 12:43:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        // start point
        vector<pair<int, int>> startPoints;
        for (int j = 0; j < m; j++) {
            startPoints.push_back({0, j});
        }
        for (int i = 1; i < n; i++) {
            startPoints.push_back({i, 0});
        }
        // each line
        for (auto [x, y] : startPoints) {
            vector<int> vals;
            int i = x, j = y;
            while (i < n && j < m) {
                vals.push_back(mat[i++][j++]);
            }
            sort(vals.begin(), vals.end());
            int index = 0;
            i = x, j = y;
            while (i < n && j < m) {
                mat[i++][j++] = vals[index++];
            }
        }
        return mat;
    }
};