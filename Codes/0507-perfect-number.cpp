/*
 * @Author: LetMeFly
 * @Date: 2021-12-31 09:10:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-31 09:12:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        int k = sqrt(num);
        for (int i = 2; i <= k; i++)
            if (num % i == 0)
                sum += i + num / i;
        if (k * k == num)
            sum -= k;
        return num == sum;
    }
};