/*
 * @Author: LetMeFly
 * @Date: 2022-04-07 20:26:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-07 20:27:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double average(vector<int>& salary) {
        int M = 1, m = 1e6, s = 0;;
        for (int& t : salary) {
            M = max(M, t);
            m = min(m, t);
            s += t;
        }
        return 1. * (s - M - m) / (salary.size() - 2);
    }
};