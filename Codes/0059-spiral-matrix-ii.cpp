/*
 * @Author: LetMeFly
 * @Date: 2022-06-04 10:20:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-04 10:24:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 👉👇👈👆

// Change From https://blog.letmefly.xyz/2022/05/28/LeetCode%200054.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int rows = n, cols = n;  // 行数，列数
        int nowDirection = 0;
        int loc = 0;
        int x = 0, y = 0;
        while (loc < rows * cols) {
            matrix[x][y] = ++loc;
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
        return matrix;
    }
};