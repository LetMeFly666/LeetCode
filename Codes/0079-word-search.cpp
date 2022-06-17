/*
 * @Author: LetMeFly
 * @Date: 2022-06-17 09:38:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-17 09:50:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<bool>> visited;
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;

    bool ok(vector<vector<char>>& a, int i, int j, string& s, int locS) {
        if (locS == s.size())
            return true;
        for (int dir = 0; dir < 4; dir++) {
            int ni = i + direction[dir][0];
            int nj = j + direction[dir][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && a[ni][nj] == s[locS]) {
                visited[ni][nj] = true;
                if (ok(a, ni, nj, s, locS + 1))
                    return true;
                visited[ni][nj] = false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string& word) {
        n = board.size(), m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (ok(board, i, j, word, 1)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};