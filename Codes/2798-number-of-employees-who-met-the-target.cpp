/*
 * @Author: LetMeFly
 * @Date: 2024-04-30 10:35:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-30 10:35:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (int t : hours) {
            ans += t >= target;
        }
        return ans;
    }
};