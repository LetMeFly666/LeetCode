/*
 * @Author: LetMeFly
 * @Date: 2022-02-12 10:01:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-12 10:25:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
typedef pair<int, int> pii;


# ifdef FirstTry
// 看成求连续的1的数量了
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    ans++;
                    queue<pii> q;
                    q.emplace(i, j);
                    while (q.size()) {
                        pii p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int tx = p.first + direction[k][0];
                            int ty = p.first + direction[k][1];
                            if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty]) {
                                grid[tx][ty] = 0;
                                q.emplace(tx, ty);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
#endif

void clearOne(int x, int y, vector<vector<int>>& grid) {
    if (!grid[x][y])
        return ;
    grid[x][y] = 0;
    queue<pii> q;
    q.emplace(x, y);
    while (q.size()) {
        pii p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int tx = p.first + direction[k][0];
            int ty = p.second + direction[k][1]; // !!! Second写成了First
            if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty]) {
                grid[tx][ty] = 0;
                q.emplace(tx, ty);
            }
        }
    }
}

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // debug(grid); //*******
        // puts("----------"); //***********
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            clearOne(i, 0, grid);
            clearOne(i, grid[0].size() - 1, grid);
        }
        // debug(grid); //*******
        // puts("----------"); //***********
        for (int j = 0; j < grid[0].size(); j++) {
            clearOne(0, j, grid);
            clearOne(grid.size() - 1, j, grid);
        }
        // debug(grid); //********
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.numEnclaves(v) << endl;
    }
    return 0;
}
#endif