/*
 * @Author: LetMeFly
 * @Date: 2023-09-08 09:24:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-08 09:24:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};