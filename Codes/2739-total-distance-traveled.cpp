/*
 * @Author: LetMeFly
 * @Date: 2024-04-25 09:34:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-25 09:38:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int added = min(additionalTank, (mainTank - 1) / 4);
        return added * 50 + (mainTank - added * 4) * 10;
    }
};