/*
 * @Author: LetMeFly
 * @Date: 2021-12-09 08:04:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-09 08:12:43
 */
// /*
//  * @Author: LetMeFly
//  * @Date: 2021-12-09 08:04:04
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-12-09 08:10:27
//  */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// class Solution {
// public:
//     bool validTicTacToe(vector<string>& board) {
//         int winTime = 0;
//         for (string& s : board) {
//             if (s[0] == s[1] && s[1] == s[2])
//                 winTime++;
//         }
//         for (int j = 0; j < 3; j++) {
//             if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
//                 winTime++;
//         }
//         int diffXO = 0;
//         for (int i = 0; i < 3; i++)
//             for (int j = 0; j < 3; j++)
//                 if (board[i][j] == 'X')
//                     diffXO++;
//                 else
//                     diffXO--;
//         return winTime < 2 && (diffXO == 0 || diffXO == 1);
//     }
// };

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (string & row : board) {
            for (char c : row) {
                xCount = (c == 'X') ? (xCount + 1) : xCount;
                oCount = (c == 'O') ? (oCount + 1) : oCount;
            }
        }
        if (oCount != xCount && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'X') && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'O') && oCount != xCount) {
            return false;
        }
        return true;
    }

    bool win(vector<string>& board, char p) {
        for (int i = 0; i < 3; ++i) {
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) {
                return true;
            }
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) {
                return true;
            }
        }
        if (p == board[0][0] && p == board[1][1] && p == board[2][2]) {
            return true;
        }
        if (p == board[0][2] && p == board[1][1] && p == board[2][0]) {
            return true;
        }
        return false;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/valid-tic-tac-toe-state/solution/you-xiao-de-jing-zi-you-xi-by-leetcode-s-c1j3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。