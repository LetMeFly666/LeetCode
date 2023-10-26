/*
 * @Author: LetMeFly
 * @Date: 2023-10-26 10:24:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-26 10:25:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int ans = 0;
        while (n) {
            ans += (num % (n % 10)) == 0;
            n /= 10;
        }
        return ans;
    }
};