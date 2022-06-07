/*
 * @Author: LetMeFly
 * @Date: 2022-06-07 08:57:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-07 09:03:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 原地修改
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        obstacleGrid[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] && (i || j)) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if (i > 0)
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                if (j > 0)
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                printf("i = %d, j = %d, obstacleGrid[%d][%d] = %d\n", i, j, i, j, obstacleGrid[i][j]);  // ***************
            }
        }
        return obstacleGrid[n - 1][m - 1];
    }
};