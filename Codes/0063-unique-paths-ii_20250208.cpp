/*
 * @Author: LetMeFly
 * @Date: 2025-02-08 09:36:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-08 09:53:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i][j] ? 0 : 1;
                    continue;
                } else if (obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = -1;
                    continue;
                }
                if (i > 0 && obstacleGrid[i - 1][j] != -1) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                }
                if (j > 0 && obstacleGrid[i][j - 1] != -1) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                }
            }
        }
        return max(obstacleGrid.back().back(), 0);
    }
};

#ifdef _WIN32
/*
[[0,0]]

1
*/
int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.uniquePathsWithObstacles(v) << endl;
    }
    return 0;
}
#endif