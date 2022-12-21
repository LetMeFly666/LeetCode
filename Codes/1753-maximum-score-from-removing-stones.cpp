/*
 * @Author: LetMeFly
 * @Date: 2022-12-21 22:46:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-21 22:48:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int v[3] = {a, b, c};
        sort(v, v + 3);
        if (v[0] + v[1] < v[2])
            return v[0] + v[1];
        return (v[0] + v[1] + v[2]) / 2;
    }
};