/*
 * @Author: LetMeFly
 * @Date: 2022-02-11 11:28:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-02-11 11:29:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums[k - 1] - nums[0];
        for (int i = 1; i + k - 1 < nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};