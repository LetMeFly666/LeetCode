/*
 * @Author: LetMeFly
 * @Date: 2023-01-06 19:02:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-06 19:03:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i++) {
            int cnt = 0, thisNum = i;
            while (thisNum) {
                cnt += thisNum % 10;
                thisNum /= 10;
            }
            ans += cnt % 2 == 0;
        }
        return ans;
    }
};