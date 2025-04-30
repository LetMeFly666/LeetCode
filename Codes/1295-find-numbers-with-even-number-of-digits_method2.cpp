/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:30:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:30:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            while (t >= 10) {
                t /= 100;
            }
            ans += t == 0;
        }
        return ans;
    }
};