/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 12:47:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 13:05:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;  // FAKE RETURN
    }
};