/*
 * @Author: LetMeFly
 * @Date: 2023-12-29 16:59:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-29 17:02:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int m1 = 1000, m2 = 1000;  // 令m1 <= m2
        for (int p : prices) {
            if (p < m2) {
                m2 = p;
                if (m1 > m2) {
                    swap(m1, m2);
                }
            }
        }
        return m1 + m2 > money ? money : money - m1 - m2;
    }
};