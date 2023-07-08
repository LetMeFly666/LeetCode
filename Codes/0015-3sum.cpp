/*
 * @Author: LetMeFly
 * @Date: 2023-07-09 07:21:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-09 07:32:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 不能去重
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            for (int l = i + 1, r = nums.size() - 1; l < r;) {
                int s = nums[l] + nums[r];
                if (s == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l + 1] == nums[l]) {
                        l++;
                    }
                    while (r - 1 > l && nums[r - 1] == nums[r]) {
                        r--;
                    }
                    l++, r--;
                }
                else if (s < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return ans;
    }
};