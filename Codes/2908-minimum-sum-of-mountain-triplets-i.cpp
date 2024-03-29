/*
 * @Author: LetMeFly
 * @Date: 2024-03-29 17:06:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-29 17:09:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> leftMin(nums.size());
        leftMin[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            leftMin[i] = min(nums[i], leftMin[i - 1]);
        }
        int rightMin = nums.back();
        int ans = 1e7;
        for (int i = nums.size() - 2; i > 0; i--) {
            if (nums[i] > leftMin[i - 1] && nums[i] > rightMin) {
                ans = min(ans, nums[i] + leftMin[i - 1] + rightMin);
            }
            rightMin = min(rightMin, nums[i]);
        }
        return ans == 1e7 ? -1 : ans;
    }
};