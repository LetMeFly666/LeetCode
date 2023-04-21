/*
 * @Author: LetMeFly
 * @Date: 2023-04-21 12:42:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-21 12:42:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 ? n * 2 : n;
    }
};