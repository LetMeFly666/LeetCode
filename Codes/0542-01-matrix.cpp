/*
 * @Author: LetMeFly
 * @Date: 2022-12-04 17:00:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-04 17:10:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
const int direcitons[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        while (q.size()) {
            pii thisNode = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = thisNode.first + direcitons[d][0];
                int ty = thisNode.second + direcitons[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (!visited[tx][ty]) {
                        visited[tx][ty] = true;
                        mat[tx][ty] = mat[thisNode.first][thisNode.second] + 1;
                        // printf("{%d, %d} -> {%d, %d}, mat[thisNode] = %d, mat[toNode] = %d\n", thisNode.first, thisNode.second, tx, ty, mat[thisNode.first][thisNode.second], mat[tx][ty]);  //***************
                        q.push({tx, ty});
                    }
                }
            }
        }
        return mat;
    }
};