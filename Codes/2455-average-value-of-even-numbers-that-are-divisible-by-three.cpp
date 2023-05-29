/*
 * @Author: LetMeFly
 * @Date: 2023-05-29 10:22:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-29 10:23:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int s = 0;
        for (int t : nums) {
            if (t % 6 == 0) {
                s += t;
                cnt++;
            }
        }
        return cnt ? s / cnt : 0;
    }
};