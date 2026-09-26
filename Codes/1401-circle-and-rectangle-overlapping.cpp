/*
 * @Author: LetMeFly
 * @Date: 2026-09-19 08:23:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-19 08:27:16
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int getClosest(int center, int x1, int x2) {
        if (x1 > center) {
            return x1;
        } else if (x2 < center) {
            return x2;
        } else {
            return center;
        }
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = getClosest(xCenter, x1, x2);
        int y = getClosest(yCenter, y1, y2);
        return (x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) <= radius * radius;
    }
};
