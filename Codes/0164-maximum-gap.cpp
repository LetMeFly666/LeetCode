/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 17:06:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 17:06:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// AC,方法一，sort，58.40%，28.52%
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};