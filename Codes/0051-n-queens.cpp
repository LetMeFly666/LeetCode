/*
 * @Author: LetMeFly
 * @Date: 2022-05-26 14:37:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-27 07:47:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<string> a;
    vector<vector<string>> ans;
    int n;
    bool ifOk(int x, int y) {  // 往(x, y)放置一个皇后是否可行
        for (int j = 0; j < n; j++) {
            if (a[x][j] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            // i + j = x + y
            int j = x + y - i;
            if (j >= 0 && j < n && a[i][j] == 'Q') {
                return false;
            }
            // i - j = x - y
            j = i - x + y;
            if (j >= 0 && j < n && a[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void goon(int line) {  // 该放第line行了
        if (line >= n) {
            ans.push_back(a);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (ifOk(line, j)) {
                a[line][j] = 'Q';
                goon(line + 1);
                a[line][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string oneLine(n, '.');
        // a = vector<string>(oneLine, n);
        for (int i = 0; i < n; i++) {
            a.push_back(oneLine);
        }
        goon(0);
        return ans;
    }
};