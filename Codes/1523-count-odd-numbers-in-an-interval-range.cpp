/*
 * @Author: LetMeFly
 * @Date: 2022-04-07 20:30:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-07 20:39:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry_ERROR

/**
 *  From Ji  |  r - l = Ji  | +1?
 *     1     |      1       |  1
 *     1     |      0       |  1
 *     0     |      1       |  1
 *     0     |      0       |  0
 * 
*/

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + !(!(low % 2) && (!(high - low) % 2));
    }
};

#else
// Learn From LeetCode

/**
 * [0, higt]的奇数个数 - [0, low - 1]
*/
class Solution {
public:
    int countOdds(int low, int high) {
        return ((high + 1) >> 1) - (low >> 1);
    }
};
#endif