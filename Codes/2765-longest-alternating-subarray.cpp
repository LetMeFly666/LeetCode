/*
 * @Author: LetMeFly
 * @Date: 2024-01-23 21:58:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-23 22:03:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = 1;
        int cnt = 1, should = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 == nums.size() || nums[i + 1] != nums[i] + should) {
                ans = max(ans, cnt);
                should = 1;
                cnt = 1;
            }
            else {
                should *= -1;
                cnt++;
            }
        }
        return ans == 1 ? -1 : ans;
    }
};