/*
 * @Author: LetMeFly
 * @Date: 2022-11-23 11:03:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-23 11:27:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int nearby(vector<vector<char>>& board, vector<int>& click) {
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int ti = click[0] + i;
                int tj = click[1] + j;
                if (ti >= 0 && ti < board.size() && tj >= 0 && tj < board[0].size()) {
                    ans += board[ti][tj] == 'M';
                }
            }
        }
        return ans;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else {
            queue<vector<int>> q;
            q.push(click);
            unordered_set<int> already;
            already.insert(click[0] * 100 + click[1]);
            while (q.size()) {
                vector<int> thisPoint = q.front();
                q.pop();
                int aroundMine = nearby(board, thisPoint);
                if (aroundMine)
                    board[thisPoint[0]][thisPoint[1]] = '0' + aroundMine;
                else {
                    board[thisPoint[0]][thisPoint[1]] = 'B';
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            int ti = thisPoint[0] + i;
                            int tj = thisPoint[1] + j;
                            if (ti >= 0 && ti < board.size() && tj >= 0 && tj < board[0].size()) {
                                if (!already.count(ti * 100 + tj)) {
                                    already.insert(ti * 100 + tj);
                                    q.push({ti, tj});
                                }
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
};