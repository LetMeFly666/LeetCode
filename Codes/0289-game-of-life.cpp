/*
 * @Author: LetMeFly
 * @Date: 2022-09-16 08:09:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-16 08:16:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 方法一：非原地
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> a(board);
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x || y) {
                            if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < m) {
                                cnt += a[i + x][j + y];
                            }
                        }
                    }
                }
                if (a[i][j]) {
                    if (cnt < 2 || cnt > 3) {
                        board[i][j] = 0;
                    }
                }
                else {
                    if (cnt == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
// 方法二：原地
/*
先
    用2表示原0现1
    用-1表示原1现0
最后再
    遍历一遍改回来
*/