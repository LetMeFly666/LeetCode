/*
 * @Author: LetMeFly
 * @Date: 2022-01-31 12:07:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-31 12:08:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num) {
            if (num % 2) num--;
            else num /= 2;
            ans++;
        }
        return ans;
    }
};