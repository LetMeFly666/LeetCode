/*
 * @Author: LetMeFly
 * @Date: 2023-05-07 16:42:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-07 16:45:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int bin[60] = {0};
        int ans = 0;
        for (int t : time) {
            ans += bin[(60 - t % 60) % 60];
            bin[t % 60]++;
        }
        return ans;
    }
};