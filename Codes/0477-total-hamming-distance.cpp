/*
 * @Author: LetMeFly
 * @Date: 2022-10-26 20:33:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-26 20:35:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int cnt0 = 0, cnt1 = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    cnt0++;
                }
                else {
                    cnt1++;
                }
            }
            ans += cnt0 * cnt1;
        }
        return ans;
    }
};