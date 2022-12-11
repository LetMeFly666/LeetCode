/*
 * @Author: LetMeFly
 * @Date: 2022-12-11 11:31:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-11 11:32:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
};