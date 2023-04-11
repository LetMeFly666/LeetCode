/*
 * @Author: LetMeFly
 * @Date: 2023-04-11 10:38:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-11 10:52:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // AC,4次循环
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 北东南西

class Solution {
public:
    bool isRobotBounded(string& instructions) {
        int nowDirection = 0;
        int x = 0, y = 0;
        for (int i = 0; i < 4; i++) {
            for (char c : instructions) {
                if (c == 'G') {
                    x += directions[nowDirection][0];
                    y += directions[nowDirection][1];
                }
                else if (c == 'L') {
                    nowDirection = (nowDirection + 3) % 4;
                }
                else {
                    nowDirection = (nowDirection + 1) % 4;
                }
            }
        }
        return !x && !y;
    }
};
#else  // FirstTry
// SecondTry
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 北东南西

class Solution {
public:
    bool isRobotBounded(string& instructions) {
        int nowDirection = 0;
        int x = 0, y = 0;
        for (char c : instructions) {
            if (c == 'G') {
                x += directions[nowDirection][0];
                y += directions[nowDirection][1];
            }
            else if (c == 'L') {
                nowDirection = (nowDirection + 3) % 4;
            }
            else {
                nowDirection = (nowDirection + 1) % 4;
            }
        }
        return nowDirection || (!x && !y);
    }
};
#endif  // FirstTry