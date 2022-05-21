/*
 * @Author: LetMeFly
 * @Date: 2022-02-09 11:01:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-09 11:04:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int bin[101] = {0};
        for (int& t : nums) {
            bin[t]++;
        }
        int ans = 0;
        for (int i = 1; i < 100; i++) {
            if (i + k <= 100) {
                ans += bin[i] * bin[i + k];
            }
        }
        return ans;
    }
};