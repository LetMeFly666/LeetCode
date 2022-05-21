/*
 * @Author: LetMeFly
 * @Date: 2022-04-07 20:19:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-07 20:20:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, sum = 0;
        while (n) {
            mul *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return mul - sum;
    }
};