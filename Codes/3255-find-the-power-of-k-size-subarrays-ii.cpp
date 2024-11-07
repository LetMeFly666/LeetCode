/*
 * @Author: LetMeFly
 * @Date: 2024-11-07 12:12:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-07 12:18:54
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1);
        int notContinue = 0;
        for (int i = 1; i < k; i++) {
            notContinue += nums[i] != nums[i - 1] + 1;
        }
        ans[0] = notContinue ? -1 : nums[k - 1];
        for (int i = 1; i + k <= nums.size(); i++) {
            notContinue -= nums[i] != nums[i - 1] + 1;
            notContinue += nums[i + k - 1] != nums[i + k - 2] + 1;
            ans[i] = notContinue ? -1 : nums[i + k - 1];
        }
        return ans;
    }
};