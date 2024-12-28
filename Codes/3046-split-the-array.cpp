/*
 * @Author: LetMeFly
 * @Date: 2024-12-28 14:38:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-28 14:40:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int times[101] = {0};
        for (int t : nums) {
            times[t]++;
            if (times[t] > 2) {
                return false;
            }
        }
        return true;
    }
};