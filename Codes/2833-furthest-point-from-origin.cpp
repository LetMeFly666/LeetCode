/*
 * @Author: LetMeFly
 * @Date: 2026-04-24 20:58:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-24 21:00:44
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int flex = 0, diff = 0;
        for (char c : moves) {
            switch (c)
            {
            case 'L':
                diff--;
                break;
            case 'R':
                diff++;
                break;
            default:
                flex++;
            }
        }
        return diff > 0 ? diff + flex : flex - diff;
    }
};
