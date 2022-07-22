/*
 * @Author: LetMeFly
 * @Date: 2022-07-22 11:21:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-22 11:43:08
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
const int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
private:
    vector<vector<bool>> isnot;  // true：不是被包围的O   false：(还)未被认定为“不是被包围的O”
    int n, m;

    void extend(int x, int y, vector<vector<char>>& a) {
        if (a[x][y] == 'O' && !isnot[x][y]) {
            queue<pii> q;
            isnot[x][y] = true;
            q.push({x, y});
            while (q.size()) {
                auto[x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + directions[d][0];
                    int ty = y + directions[d][1];
                    if (tx >=0 && tx < n && ty >= 0 && ty < m) {
                        if (a[tx][ty] == 'O' && !isnot[tx][ty]) {
                            isnot[tx][ty] = true;
                            q.push({tx, ty});
                        }
                    }
                }
            }
            #ifdef _WIN32
            debug(isnot);
            #endif
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        isnot = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            extend(i, 0, board);
            extend(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            extend(0, j, board);
            extend(n - 1, j, board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !isnot[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        #ifdef _WIN32
        debug(isnot);
        #endif
    }
};

/*
[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

*/
#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<vector<char>> v = stringToVectorVectorC(s);
        debug(v);
        Solution sol;
        sol.solve(v);
        debug(v);
    }
    return 0;
}
#endif