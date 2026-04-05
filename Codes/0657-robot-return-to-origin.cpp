/*
 * @Author: LetMeFly
 * @Date: 2026-04-05 13:03:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-05 13:26:08
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            switch (c) {
            case 'U':
                y++;
                break;

            case 'D':
                y--;
                break;

            case 'L':
                x--;
                break;

            case 'R':
                x++;
                break;
            
            default:
                break;
            }
        }
        return !x && !y;
    }
};