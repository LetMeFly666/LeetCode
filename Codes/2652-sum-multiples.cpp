/*
 * @Author: LetMeFly
 * @Date: 2023-10-17 09:06:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-17 09:26:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n;

    inline int f(int k) {
        return (k + n / k * k) * (n / k) / 2;  // (首项 + 尾项) * 项数 / 2
    }
public:
    int sumOfMultiples(int n) {
        this->n = n;
        return f(3) + f(5) + f(7) - f(15) - f(21) - f(35) + f(105);
    }
};