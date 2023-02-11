/*
 * @Author: LetMeFly
 * @Date: 2023-02-11 09:56:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-11 09:58:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2])
            return amount[2];
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
};