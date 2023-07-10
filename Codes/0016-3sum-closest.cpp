/*
 * @Author: LetMeFly
 * @Date: 2023-07-10 08:51:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-10 09:00:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int finding = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int diff = finding - nums[l] - nums[r];
                if (diff == 0) {
                    return target;
                }
                else if (diff > 0) {  // target > nums[i] + nums[l] + nums[r]
                    l++;
                }
                else {
                    r--;
                }
                if (abs(diff) < abs(ans - target)) {
                    ans = target - diff;
                }
            }
        }
        return ans;
    }
};