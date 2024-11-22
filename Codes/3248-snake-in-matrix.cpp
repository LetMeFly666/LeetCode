/*
 * @Author: LetMeFly
 * @Date: 2024-11-21 22:59:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-21 23:02:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 开始看题
// 开始解题
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for (string& command : commands) {
            switch (command[0])
            {
            case 'U':
                ans -= n;
                break;
            case 'D':
                ans += n;
                break;
            case 'L':
                ans--;
                break;
            default:  // 'R'
                ans++;
                break;
            }
        }
        return ans;
    }
};