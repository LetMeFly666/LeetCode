/*
 * @Author: LetMeFly
 * @Date: 2022-05-27 09:49:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-27 09:50:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool a[9][9] = {false};
    int ans = 0;
    int n;
    bool ifOk(int x, int y) {  // 往(x, y)放置一个皇后是否可行
        for (int j = 0; j < n; j++) {
            if (a[x][j]) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][y]) {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            // i + j = x + y
            int j = x + y - i;
            if (j >= 0 && j < n && a[i][j]) {
                return false;
            }
            // i - j = x - y
            j = i - x + y;
            if (j >= 0 && j < n && a[i][j]) {
                return false;
            }
        }
        return true;
    }
    void goon(int line) {  // 该放第line行了
        if (line >= n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (ifOk(line, j)) {
                a[line][j] = true;
                goon(line + 1);
                a[line][j] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        goon(0);
        return ans;
    }
};