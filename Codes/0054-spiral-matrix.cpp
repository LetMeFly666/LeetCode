/*
 * @Author: LetMeFly
 * @Date: 2022-05-28 11:11:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-28 16:22:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// 修改原数组
#define ALREADY 101
#define ifOK(x, y) if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] != ALREADY)
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 👉👇👈👆

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() * matrix[0].size();
        vector<int> ans(n);
        int nowDirection = 0;  // 现在的方向
        int loc = 0;  // 遍历了几个元素了
        int x = 0, y = 0;  // 当前应该遍历的位置
        while (loc < n) {
            ans[loc++] = matrix[x][y];
            matrix[x][y] = ALREADY;
            int nx = x + directions[nowDirection][0];
            int ny = y + directions[nowDirection][1];
            ifOK(nx, ny) {
                x = nx, y = ny;
            }
            else {
                nowDirection = (nowDirection + 1) % 4;
                x += directions[nowDirection][0];
                y += directions[nowDirection][1];
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry：不修改原数组
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 👉👇👈👆

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();  // 行数，列数
        vector<int> ans(rows * cols);
        int nowDirection = 0;
        int loc = 0;
        int x = 0, y = 0;
        while (loc < rows * cols) {
            ans[loc++] = matrix[x][y];
            if (nowDirection == 0 && x + y == cols - 1) {  // 右转下
                nowDirection = 1;
            }
            else if (nowDirection == 1 && x - y == rows - cols) {  // 下转左
                nowDirection = 2;
            }
            else if (nowDirection == 2 && x + y == rows - 1) {  // 左转上
                nowDirection = 3;
            }
            else if (nowDirection == 3 && x - y == 1) {  // 上转右
                nowDirection = 0;
            }
            x += directions[nowDirection][0];
            y += directions[nowDirection][1];
            // // DebugBegin
            // printf("x = %d, y = %d, nowDirection = %d\n", x, y, nowDirection);
            // if (!(x >= 0 && x < rows && y >= 0 && y < cols)) {
            //     printf("Error!\n");
            //     break;
            // }
            // // DebugEnd
        }
        return ans;
    }
};
#endif  // FirstTry