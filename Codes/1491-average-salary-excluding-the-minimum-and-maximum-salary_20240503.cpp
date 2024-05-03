/*
 * @Author: LetMeFly
 * @Date: 2024-05-03 14:32:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-03 14:33:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double average(vector<int>& salary) {
        int m = salary[0], M = m, s = 0;
        for (int t : salary) {
            m = min(m, t);
            M = max(M, t);
            s += t;
        }
        return (double)(s - m - M) / (salary.size() - 2);
    }
};