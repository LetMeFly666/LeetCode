/*
 * @Author: LetMeFly
 * @Date: 2024-07-03 19:23:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-03 19:23:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int getSum(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = getSum(x);
        return x % sum == 0 ? sum : -1;
    }
};