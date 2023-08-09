/*
 * @Author: LetMeFly
 * @Date: 2023-08-09 08:06:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-09 08:07:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, cnt = 0;
        while (n) {
            mul *= n % 10;
            cnt += n % 10;
            n /= 10;
        }
        return mul - cnt;
    }
};