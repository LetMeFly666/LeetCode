/*
 * @Author: LetMeFly
 * @Date: 2022-09-18 08:23:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-18 08:37:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> point;
const int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int numTo = 2;
        unordered_map<int, int> num2area;
        num2area[0] = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int thisNum = numTo;
                    int thisArea = 1;
                    numTo++;
                    queue<point> points;
                    points.push({i, j});
                    grid[i][j] = thisNum;
                    while (points.size()) {
                        point thisPoint = points.front();
                        points.pop();
                        for (int d = 0; d < 4; d++) {
                            int tx = thisPoint.first + directions[d][0];
                            int ty = thisPoint.second + directions[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                                if (grid[tx][ty] == 1) {
                                    grid[tx][ty] = thisNum;
                                    points.push({tx, ty});
                                    thisArea++;
                                }
                            }
                        }
                    }
                    num2area[thisNum] = thisArea;
                }
            }
        }
        if (numTo == 2)
            return 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> nearby;
                    for (int d = 0; d < 4; d++) {
                        int tx = i + directions[d][0];
                        int ty = j + directions[d][1];
                        if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                            nearby.insert(grid[tx][ty]);
                        }
                    }
                    int cnt = 1;
                    for (int num : nearby) {
                        cnt += num2area[num];
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans ? ans : n * n;
    }
};