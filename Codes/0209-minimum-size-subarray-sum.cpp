/*
 * @Author: LetMeFly
 * @Date: 2022-08-22 10:34:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-22 10:38:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int l = -1;  // (l, r]
        int s = 0;
        for (int r = 0; r < nums.size(); r++) {
            s += nums[r];
            while (l + 1 < r && s - nums[l + 1] >= target) {
                s -= nums[l + 1];
                l++;
            }
            if (s >= target) {
                ans = min(ans, r - l);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};