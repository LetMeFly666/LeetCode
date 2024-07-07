/*
 * @Author: LetMeFly
 * @Date: 2024-07-07 16:51:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-07 16:59:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
class Solution {
private:
    inline bool inBorad(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        for (int d = 0; d < 8; d++) {
            int x = rMove, y = cMove;
            int dx = directions[d][0], dy = directions[d][1];
            x += dx, y += dy;
            if (!inBorad(x, y)) {
                continue;
            }
            if (board[x][y] != (color ^ 'B' ^ 'W')) {
                continue;
            }
            while (inBorad(x + dx, y + dy)) {
                x = x + dx, y = y + dy;
                if (board[x][y] == color) {
                    return true;
                }
                if (board[x][y] == '.') {
                    break;
                }
            }
        }
        return false;
    }
};

/*
..W.BWWB
BW.W.WBB
.WBWW.WW
WW.W..BB
BWBBWWB.
W.W..BWW
B.BB..BB
.W.W.W.W

5 4 W
*/