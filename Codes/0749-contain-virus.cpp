/*
 * @Author: LetMeFly
 * @Date: 2022-07-18 11:05:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-18 12:10:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
    0: 空地
    1: 活の病毒
    2: 被控制の病毒
*/
const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
    int ans = 0;
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int n = isInfected.size();
        int m = isInfected[0].size();
        while (true) {
            bool has1 = false;

            int max1adjacent = 0;  // 活病毒的最大相邻待感染区域的大小
            map<int, pair<int, int>> area2loc;  // [<待感染区域的面积, 其中一个活病毒的坐标>]
            map<pair<int, int>, int> loc2wallNum;  // [<活病毒的坐标, 需要添加的墙的数量>]
            vector<vector<bool>> visited(n, vector<bool>(m, false));  // 哪个区域被遍历过了
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {  // 这是一个活病毒的位置 && 这个区域还没有被遍历过
                        has1 = true;
                        visited[i][j] = true;
                        pair<int, int> oneOfThisArea = {i, j};
                        int thisAdjacent = 0;  // 这个待感染区域的大小
                        int thisWallNum = 0;  // 控制这个区域的话，需要安装隔离墙的数量

                        queue<pair<int, int>> q;
                        q.push({i, j});
                        while (q.size()) {
                            auto[x, y] = q.front();
                            q.pop();
                            for (int d = 0; d < 4; d++) {
                                int tx = x + direction[d][0];
                                int ty = y + direction[d][1];
                                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {  // 下一个单元在合法范围内
                                    if (isInfected[tx][ty] == 1 && !visited[tx][ty]) {  // 下一个单元是未被标记的病毒
                                        visited[tx][ty] = true;
                                        q.push({tx, ty});
                                    }
                                    else if (isInfected[tx][ty] == 0) {  // 下一个单元格是待感染区域
                                        thisWallNum++;  // 不论这个待感染区域是否被统计过，都要安装隔离墙（区域只统计一次，但隔离墙最多要安装4面）
                                        if (!visited[tx][ty]) {  // 这个区域还未被统计过
                                            visited[tx][ty] = true;
                                            thisAdjacent++;
                                        }                                        
                                    }
                                }
                            }
                        }

                        max1adjacent = max(max1adjacent, thisAdjacent);
                        area2loc[thisAdjacent] = oneOfThisArea;
                        loc2wallNum[oneOfThisArea] = thisWallNum;
                    }
                }
            }
            if (!max1adjacent) {  // 待感染区域面积为0，说明没有活病毒了或者全部被病毒感染了（其实似乎不用has1变量即可）
                break;
            }
            pair<int, int> oneOfThisArea = area2loc[max1adjacent];
            ans += loc2wallNum[oneOfThisArea];

            queue<pair<int, int>> q;
            q.push(oneOfThisArea);
            isInfected[oneOfThisArea.first][oneOfThisArea.second] = 2;
            while (q.size()) {
                auto[x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + direction[d][0];
                    int ty = y + direction[d][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if (isInfected[tx][ty] == 1) {
                            isInfected[tx][ty] = 2;
                            q.push({tx, ty});
                        }
                    }
                }
            }

#ifdef FirstTry  // 搜索
            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (isInfected[x][y] == 1 && !visited[x][y]) {
                        visited[x][y] = true;
                        q.push({x, y})                        ;
                        for (int d = 0; d < 4; d++) {
                            int tx = x + direction[d][0];
                            int ty = y + direction[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (isInfected[tx][ty] == 0) {  // 空地
                                    isInfected[tx][ty] = 1;
                                    visited[tx][ty] = true;  // 防止继续感染拓展
                                }
                                else if (isInfected[tx][ty] == 1 && !visited[tx][ty]) {  // 还是病毒 && 还未被处理过
                                    visited[tx][ty] = true;
                                    q.push({tx, ty});
                                }
                            }
                        }
                    }
                }
            }
#else  // FirstTry
            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (isInfected[x][y] == 1 && !visited[x][y]) {
                        visited[x][y] = true;
                        for (int d = 0; d < 4; d++) {
                            int tx = x + direction[d][0];
                            int ty = y + direction[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (isInfected[tx][ty] == 0) {
                                    isInfected[tx][ty] = 1;
                                    visited[tx][ty] = true;
                                }
                            }
                        }
                    }
                }
            }
#endif  // FirstTry

            if (!has1)
                break;
        }
        return ans;
    }
};