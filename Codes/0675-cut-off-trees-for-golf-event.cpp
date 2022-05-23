/*
 * @Author: LetMeFly
 * @Date: 2022-05-23 10:17:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-23 11:15:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct Tree {
    int x, y;
    Tree() {}
    Tree(int x, int y) : x(x), y(y) {}
    bool operator == (const Tree& t2) {
        return x == t2.x && y == t2.y;
    }
};
const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
typedef pair<Tree, int> pti;
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        vector<Tree> trees;
        // trees.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j);
                }
            }
        }
        function<bool(Tree, Tree)> cmp = [&forest](const Tree& a, const Tree& b) {
            return forest[a.x][a.y] < forest[b.x][b.y];
        };
        sort(trees.begin(), trees.end(), cmp);
        trees.insert(trees.begin(), {0, 0});  // 必须排序后再插入(0, 0)点
        int ans = 0;
        function<int(Tree, Tree)> getMinDistance = [&forest, &n, &m](const Tree& a, const Tree& b) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            queue<pti> q;
            q.push({a, 0});
            visited[a.x][a.y] = true;
            while (q.size()) {
                auto [t, d] = q.front();
                q.pop();
                if (t == b) {
                    return d;
                }
                for (int i = 0; i < 4; i++) {
                    int tx = t.x + directions[i][0];
                    int ty = t.y + directions[i][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m && !visited[tx][ty] && forest[tx][ty]) {
                        visited[tx][ty] = true;
                        q.push({{tx, ty}, d + 1});
                    }
                }
            }
            return -1;
        };
        // for (int i = 0; i < trees.size(); i++) {
        //     cout << forest[trees[i].x][trees[i].y] << ' ';
        // }
        // puts("");
        for (int i = 1; i < trees.size(); i++) {
            int thisDistance = getMinDistance(trees[i - 1], trees[i]);
            printf("[%d, %d](%d) ->  [%d, %d](%d): %d\n", trees[i - 1].x, trees[i - 1].y, forest[trees[i - 1].x][trees[i - 1].y], trees[i].x, trees[i].y, forest[trees[i].x][trees[i].y], thisDistance);
            if (thisDistance == -1) {
                return -1;
            }
            ans += thisDistance;
        }
        return ans;
    }
};

class Solution_LeetCode_TiJie {  // LeetCode题解：Debug用
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return 0;
        }

        int row = forest.size();
        int col = forest[0].size();
        int step = 0;
        queue<pair<int, int>> qu;
        vector<vector<bool>> visited(row, vector<bool>(col, false));         
        qu.emplace(sx, sy);
        visited[sx][sy] = true;
        while (!qu.empty()) {
            step++;
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                auto [cx, cy] = qu.front();
                qu.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        if (!visited[nx][ny] && forest[nx][ny] > 0) {
                            if (nx == tx && ny == ty) {
                                return step;
                            }
                            qu.emplace(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int row = forest.size();
        int col = forest[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j);
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int> & a, const pair<int, int> & b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });

        int cx = 0;
        int cy = 0;
        int ans = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);
            printf("[%d, %d](%d) ->  [%d, %d](%d): %d\n", cx, cy, forest[cx][cy], trees[i].first, trees[i].second, forest[trees[i].first][trees[i].second], steps);
            if (steps == -1) {
                return -1;
            }
            ans += steps;
            cx = trees[i].first;
            cy = trees[i].second;
        }
        return ans;
    }
};

/*
[[54581641,64080174,24346381,69107959],[86374198,61363882,68783324,79706116],[668150,92178815,89819108,94701471],[83920491,22724204,46281641,47531096],[89078499,18904913,25462145,60813308]]

57
*/
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.cutOffTree(v) << endl;
        // Solution_LeetCode_TiJie solLee;
        // cout << solLee.cutOffTree(v) << endl;
    }
    return 0;
}
#endif