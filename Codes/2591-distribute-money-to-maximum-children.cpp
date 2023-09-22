/*
 * @Author: LetMeFly
 * @Date: 2023-09-22 13:14:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-22 13:15:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money > 8 * children) {
            return children - 1;
        }
        if (money == 8 * children - 4) {
            return children - 2;
        }
        return (money - children) / 7;
    }
};