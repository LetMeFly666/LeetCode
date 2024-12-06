/*
 * @Author: LetMeFly
 * @Date: 2024-12-07 00:02:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-07 00:18:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA，只进行了一次break
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;
        for (x = 0; x < board.size(); x++) {
            for (y = 0; y < board[0].size(); y++) {
                if (board[x][y] == 'R') {
                    break;
                }
            }
        }
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            for (int step = 1; ; step++) {
                int nx = x + directions[d][0] * step;
                int ny = y + directions[d][1] * step;
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == 'B') {
                    break;
                }
                ans += board[nx][ny] == 'p';
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;
        for (x = 0; x < board.size(); x++) {
            for (y = 0; y < board[0].size(); y++) {
                if (board[x][y] == 'R') {
                    goto loop;
                }
            }
        }
        loop:;
        int ans = 0;
        for (int d = 0; d < 4; d++) {
            for (int step = 1; ; step++) {
                int nx = x + directions[d][0] * step;
                int ny = y + directions[d][1] * step;
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == 'B') {
                    break;
                }
                if (board[nx][ny] == 'p') {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
// [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        vector<vector<char>> v = stringToVectorVectorC(s);
        cout << sol.numRookCaptures(v) << endl;
    }
    return 0;
}
#endif