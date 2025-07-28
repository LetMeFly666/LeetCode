/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 21:39:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 21:45:22
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int last = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > last && nums[i] > nums[i + 1]) {
                ans++;
            } else if (nums[i] < last && nums[i] < nums[i + 1]) {
                ans++;
            }
            if (nums[i] != nums[i - 1]) {
                last = nums[i];
            }
        }
        return ans;
    }
};